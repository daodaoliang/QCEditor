#include "BoxList.h"
#include "qmenu.h"
#include "qtreewidget.h"
#include "Editor/Common.h"
#include "Editor/AttributeAccessor.h"
#include "qobjectdefs.h"
#include "qcoreevent.h"

Q_DECLARE_METATYPE(Node*);

BoxList::BoxList(QWidget *parent)
	: QWidget(parent)
	, _index(0)
{
	Global::boxList = this;

	ui.setupUi(this);
	connect(ui.treeWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showMenu(const QPoint&)));
	connect(ui.treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), this, SLOT(selectedNode(QTreeWidgetItem*, QTreeWidgetItem*)));
}

BoxList::~BoxList()
{

}

void BoxList::selectedNode(QTreeWidgetItem* curr, QTreeWidgetItem* prev)
{
	MyTreeWidgetItem* myitem = (MyTreeWidgetItem*)curr;
	emit onSelectNode(myitem->node);
}

MyTreeWidgetItem* BoxList::add(const QString& name, QTreeWidgetItem* parent)
{
	MyTreeWidgetItem *item = new MyTreeWidgetItem();
	item->setCheckState(0, Qt::Checked);
	item->setText(0, name);

	if (parent == nullptr)
		ui.treeWidget->insertTopLevelItem(0, item);
	else
		parent->addChild(item);

	return item;
}

void BoxList::showMenu(const QPoint& pos)
{
	QMenu* menu = new QMenu();

	const AAManager::GroupMap& map = AAManager::getInstance().getGroups();

	for (auto iter : map)
	{
		std::string name = iter.first;

		QAction* act = new QAction(name.c_str(), menu);
		//connect(act, SIGNAL(triggered()), this, SLOT(doAddWidget()));
		menu->addAction(act);
	}
	connect(menu, SIGNAL(triggered(QAction *)), this, SLOT(doAddWidget(QAction *)));
	_currentWidget = (MyTreeWidgetItem*) ui.treeWidget->itemAt(pos);

	menu->exec(QCursor::pos());
}

void BoxList::doAddWidget(QAction* act)
{
	std::string typeName = std::string(act->text().toUtf8());
	MyTreeWidgetItem* newItem = add("new" + QString::number(_index), _currentWidget);

	newItem->setSelected(true);

	if (!_currentWidget)
		return;

	if (_currentWidget->childCount() == 1)
		_currentWidget->setExpanded(true);

	_currentWidget->setSelected(false);

	const AAManager::GroupMap& map = AAManager::getInstance().getGroups();
	AccessorGroup* info = map.at(typeName);

	newItem->node = info->ctor->operator()();
	_currentWidget->node->addChild(newItem->node);

	NodeInfo nodeinfo;
	nodeinfo.node = newItem->node;
	nodeinfo.typeName = typeName;

	emit newNode(&nodeinfo);
	emit onSelectNode(newItem->node);//

	_currentWidget = NULL;
}

void BoxList::updateList(Node* root)
{
	MyTreeWidgetItem *item = add("root");
	item->node = root;
	
	//for each child
}
