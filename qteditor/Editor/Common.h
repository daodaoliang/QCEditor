#ifndef _COMMON_H_
#define _COMMON_H_

#include "2d/CCNode.h"
#include "qstring.h"
#include "SceneCtrl.h"
#include "BoxList.h"
#include "EditorMain.h"
#include <string>

USING_NS_CC;

class NodeInfo
{
public:
	Node* node;
	std::string typeName;
};


class Global
{
public:
	static SceneCtrl* sceneCtrl;
	static BoxList* boxList;
	static EditorMain* editorMain;
};

#endif//_COMMON_H_