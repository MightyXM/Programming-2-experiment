<h1><center>实验一  VC6使用与cout输出程序设计</center></h>
<h4><center>计算机学院 20305055 熊明</center></h4>

## 一、实验目的

1. 掌握c++程序设计流程和VC集成开发环境使用。
2. 掌握c++程序的基本要素。
3. 掌握标准输入(iostream库中的对象cout)的简单使用。
4. 初步了解程序错误信息及其调试方法。
5. 初步了解程序维护

## 二、实验原理

（略）

## 三、实验内容

### 1.程序调试

> 根据 vc6.0 使用文档本教材 2.2.4 VC 进行程序设计的流程，把下面 C++源程序拷贝到新建
>
> 工程中，编译运行程序，显示器屏幕上会报告一些语法错误以及出现错误的行号。请认真分
>
> 析错误提示，分析错误原因，进行程序调试，修改错误
>
> \#include<iostream.h> 
>
> int main() 
>
> { 
>
> cout<<“您好！中山大学欢迎您，愿您喜欢 C++程序设计。”<<endl; 
>
> cout<<2020; 
>
> cout<<\n; 
>
> cout<<20。1; 
>
> cout<<endl; 
>
> system(“pause”)
>
> return 0;
>
> }

#### 修改后的代码：

```c++
//#include<iostream.h>
#include<iostream>
using namespace std;
int main() 
{ 
cout<<"“您好！中山大学欢迎您，愿您喜欢 C++程序设计。”"<<endl; 
cout<<2020; 
// cout<<\n; 
cout<<endl;
cout<<20.1; 
cout<<endl; 
// system(“pause”)
system("pause");
return 0;
}
```

#### 运行结果：

![image-20230301151858836](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230301151858836.png)

#### 错误原因分析：

1. iostream.h里面定义的所有类以及对象都是在全局空间里，所以可以直接用cout 。但在iostream里面，它所定义的东西都在名字空间std里面，所以必须加上 using namespace std;才能使用cout。iostream是C++的头文件，iostream.h是C的头文件。标准的C++头文件没有.h扩展名，将以前的C的头文件转化为C++的头文件后，有时加上c的前缀表示来自于c，例如cmath就是由math.h变来的。（因为我的编译器可能用不了iostream.h库，所以我转换成了iostream）
2. 输出字符串要用双引号之间。
3. 括号内的字符串必须要用英文输入法下的。
4. \n可以用endl代替

### 小票设计

> 用 cout 语句设计一个 C++程序，输出购物小票清单。自己安排输出格式，越美观越好。
>
> 1） 输入输出分析及算法；要求写出具体步骤
>
> 2） 编程源代码加注释；
>
> 3） 调试与测试；要求写出具体步骤
>
> 4） 遇到的问题及解决方法；

#### 代码：

```c++
#include<iostream>
using namespace std;
int main(){
    cout<<"          某某购物商场         "<<endl;
    cout<<"票号0120341    机号3013   工号1013"<<endl;
    cout<<"交易时间020-11-25 16:53:37"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"商品名称     单价        数量        总计"<<endl;
    cout<<"大白兔奶糖   57.6         2          115.2￥"<<endl;
    cout<<"水果奶昔     12.4         1          12.4￥"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"金额：127.6￥ 折扣：0"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"支付方式：微信   找零：0.00"<<endl;
    cout<<"商品质量问题七日内退换\n生鲜八小时日退换\n此单为唯一购物凭证发票当日索取"<<endl;
}
```

#### 运行结果：

![image-20230301153606643](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230301153606643.png)

## 四、实验体会

了解了c++的报错内容和一些修改方法。学会了调试程序找错。