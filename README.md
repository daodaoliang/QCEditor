![preview][]

#QCEditor

**QCEditor**是一个简单的cocos2d-x编辑器。 Qt和Cocos-x 都能跨平台，理论上是能够跨平台的。名字是 Qt 和 Cocos2d-x 的首字母缩写。写这个编辑器的目的是为了实现一个能摆放ui控件位置的功能，我们在游戏开发过程中通常也只会用到这个功能。

**QCEditor**的渲染使用的是cocos2d-x本身的渲染，所以说在编辑器里面编辑的效果和游戏中的效果会一模一样，在编辑器里面添加的控件代码、解析代码，不用再到项目里面实现一次，只需要拷贝过去就能用。

##功能添加
添加新的属性和控件非常方便，只需要按照下面格式添加，将会自动与Node绑定，并且自动添加到存储功能中(目前该功能还不完善)。理论上通过这种方式，能够编辑cocos2d-x里所有可视化组件，甚至其他一些组件。

```C++
		ATTR("Local Z Order", &Node::getLocalZOrder, &Node::setLocalZOrder, int, 0);
		ATTR("Global Z Order", &Node::getGlobalZOrder, &Node::setGlobalZOrder, float, 0.0);
		ATTR("Visible", &Node::isVisible, &Node::setVisible, bool, true);
		ATTRSTEP("Scale X", &Node::getScaleX, &Node::setScaleX, float, 1.0, 0.1);//don't using 1.0f,
		ATTRSTEP("Scale Y", &Node::getScaleY, &Node::setScaleY, float, 1.0, 0.1);
		ATTR("Rotation", &Node::getRotation, &Node::setRotation, float, 0);
		ATTR("Position", &Node::getPosition, &Node::setPosition, Vec2, Vec2(0, 0));
		ATTR("Tag", &Node::getTag, &Node::setTag, int, 0);
		ATTRMixed("Name", &Node::getName, &Node::setName, std::string, std::string());
		ATTRMMS("Anchor Pos", &Node::getAnchorPoint, &Node::setAnchorPoint, Vec2, Vec2(0.5, 0.5), Vec2(0, 0), Vec2(1, 1), Vec2(0.1, 0.1));
```

```XML
	<Property name="Local Z Order"	value="1" />
	<Property name="Global Z Order"	value="1.0" />
	<Property name="Visible"	value="true" />
	<Property name="Scale X"	value="1.0" />
	<Property name="Scale Y"	value="1.0" />
	<Property name="Rotation"	value="0.0" />
	<Property name="Position"	value="0 0" />
	<Property name="Tag"	value="0" />
	<Property name="Name"	value="node" />
	<Property name="Anchor Pos"	value="0 0" />
```

![attr][]


##编译过程
* VS2013 + Qt 5.4.1 + QtCreator
* 先用QtCreator编译qteditor\qtpropertybrowser\buildlib\buildlib.pro
* 然后打开工程修改Qt版本为你本机版本
* 编译运行

##项目地址

* oschina  [http://git.oschina.net/qcdong/QCEditor](http://git.oschina.net/qcdong/QCEditor)
* github   [https://github.com/CaptainCN/QCEditor](https://github.com/CaptainCN/QCEditor)


##其他
个人力量有限，如果有小伙伴一起来搞就好啦，欢迎提供代码。

##License
Licensed under the MIT license, see [LICENSE](LICENSE) for details.


[preview]: images/preview.jpg
[attr]: images/attr.png