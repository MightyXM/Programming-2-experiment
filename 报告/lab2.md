<h1><center>实验二 数据类型、常量、变量、运算表达式</center></h1>
<h4><center>计算机学院 熊明 20305055</center></h4>

## 一、实验目的

1. 进一步熟悉C++程序设计流程：编辑、编译、连接、运行、调试测试。
2. 熟悉C++语言数据类型，掌握定义整型、字符型、实型变量以及对它们赋值的方法。
3. 学会使用C++的运算符及表达式。
4. 掌握运算符的优先级。
5. 学会常见数学函数库函数的调用。
6. 初步了解string类，并会简单使用。
7. 掌握不同的类型数据之间运算的类型转换规则，理解自动类型转换和会使用强制类型转换。
8. 掌握vc++调试程序，学会查看变量和表达式的值。

## 二、实验原理

（略）

## 三、实验内容

1. 计算圆的面积

   > 利用计算机计算圆的面积

   ```c++
   #include<iostream>
   #include<iomanip>
   #define PI 3.14159
   using namespace std;
   int main() {
   	double r,s;
   	cin >> r;
   	s = PI * r * r;
   	cout << "半径为" << fixed << setprecision(2)<< r << "的圆面积为" << s << endl;
   }
   ```

2. > 参考上述代码，实现右侧三幅图，要求用到变量，运算表达式，顺序结构程序等理论课知识。第三幅图得出什么结论？

   1. 画圆

      ```c++
      #include <graphics.h> // 引用图形库头文件
      #include <conio.h>
      int main()
      {
      	initgraph(640, 480); // 创建绘图窗口，大小为 640x480 像素
      	fillcircle(320, 240, 100); // 画圆，圆心(320, 240)，半径 100
      	_getch(); // 按任意键继续
      	closegraph(); // 关闭绘图窗口
      	return 0;
      }
      ```

      结果：

      ![image-20230307212727360](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230307212727360.png)

   2. 在一个垂直线上画n个圆

      ```c++
      #include <graphics.h> // 引用图形库头文件
      #include <conio.h>
      #include<iostream>
      using namespace std;
      int main()
      {
      	int n;
      	cin >> n;
      	int r;
      	r = 480 / (2 * n);
      	initgraph(640, 480);
      	for (int i = 0; i < n; i++) {
      		fillcircle(320,r+2*r*i,r);
      	}
      	_getch();
      	closegraph();
      }
      ```

      结果以5个圆为例：

      ![image-20230307221050729](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230307221050729.png)

   3. 顺序结构绘图：

      ```c++
      #include <graphics.h> 
      #include<conio.h>
      #include<iostream>
      using namespace std;
      int main()
      {
      
          initgraph(640, 480);
      
          fillcircle(160, 240, 25);
          fillcircle(70, 240, 50);
          fillcircle(250, 240, 50);
          fillcircle(160, 330, 50);
          fillcircle(160, 150, 50);
          fillcircle(500, 240, 50);
          fillcircle(600, 240, 25);
          fillcircle(400, 240, 25);
          fillcircle(500, 340, 25);
          fillcircle(500, 140, 25);
      
          _getch();
          closegraph();
          return 0;
      }
      ```

      结果：

      ![image-20230307224015192](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230307224015192.png)

## 四、实验心得体会

设置画布的参数及圆的半径时没有合理留下空间，需进一步改正。