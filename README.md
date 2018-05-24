# RGPgame
更新内容如下：
新增constant.h头文件，放置各派生类需要使用的Command枚举类型
注：这里我想了一下，还是需要将一些内容的东西整合起来。因为将来window.h会有容纳
Live_player指针的单向列表，但是每个类和window之间的交互都要靠派生类的
react函数实现，所以在Live_player里面就需要有虚函数版本的react(Command cmd)，
具体该函数的工作交由派生类完成。
但是不同的派生类有不同的Command 枚举类型，在Live_player里面没有办法写这个函数
的参数，所以必须将所有派生类的Command枚举类型合并起来，放到constant.h文件中。
需要使用这一枚举类型的文件，开头需要include "constant.h"
constant.h中的枚举类型前的class关键字是C++11的新特性。因为将来会有不同的公用枚举类型（比如我现在要实现的信号函数的参数），为防止不同的公用枚举类型内部的词语重名而在外面使用产生冲突，也为了强调使用的是哪一个枚举类型，添加了这一特性。
这一特性虽然加了class关键字，但是和类没有半点关系，只是在使用的时候前面要加上作用域标识符。（参见enemy.cpp、princess的react函数，window.cpp的
mousemoveevent,mousepressevent等函数）
使用的时候前面要加上Command::
window.cpp的KeyPressevent里面的Qt::Key_A和MousePressEvent里面的Qt::LeftButton也是系统中提供的enum class类型

Live_player的改动：
1.HeartDistanceWith()函数，传入Abstract_obj类型或者其派生类，返回调用该函数类的受伤中心到传入类坐标中心的距离
2.bool inHurtable_range（）传入Abstract_obj类型，返回传入类位置坐标是否在本对象的可受伤范围
3.bool inAttack_range()传入Abstract_obj类型，返回传入类位置坐标是否可以触发我方的攻击状态
4.将Abstract_obj类的私有变量_speed和_destination以及相关函数（move,setDestination,getDx,getDy,getSpeed,getDestinationX,getDestinationY,setSpeed）都上移到了Live_player里面
5.新增void react(Command cmd)=0纯虚函数，必须在派生类定义这一函数。

Abstract_player变动：
1.move（）变成纯虚函数
2.新增int ObjDistanceWith（const Abstract_obj &）函数，传入Abstract_obj类或者它的派生类，返回本类和传入类位置坐标之间的距离
3.将Abstract_obj从QObject public继承，方便信号与槽机制的使用