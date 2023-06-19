<h1>
    <center>
        实验六、作用域、生存期及函数实验
    </center>
</h1>
<h4>
    <center>
        计算机学院 熊明 20305055
    </center>
</h4>


## 一、实验目的

1. 了解变量的作用域、生存期和可见性。
2.  理解变量和函数的声明、定义、调用的区别
3.  递归函数
4.  函数重载、函数模板

## 二、实验原理

◆ 任何一种编程中，作用域是程序中定义的变量所存在的区域，超过该区域变量就不能被访问。

◆ 作用域是指标识符在程序中可见的部分，可以看作是标识符的一个有效范围。按其作用域范围可分为

全局作用域和局部作用域。

◆ 全局作用域表现为标识符从定义处开始可以在整个程序或其他程序中进行引用

◆ 局部作用域则只能在局部范围内引用。

◆ C++作用域分以下几类：类作用域、局部作用域、命名空间作用域、全局作用域。

◆ C++函数名称具有全局作用域，如果变量和常数的名称也在所有函数和命名空间之外声明也具有全局

作用域。

◆ 在块内{ }声明的变量和常量具有局部作用域，它们在块外不可见。

◆ 函数的参数与函数最外层块中声明的局部变量具有相同的作用域。

◆ 如果嵌套块内部和外部包含具有相同名称的本地声明标识符，嵌套块内部标识符具有名称优先级，覆

盖外部标识符，即就近原则

## 三、实验内容

1. 注释出下面程序中的全局变量和局部变量，分析程序运行结果,说明结果的原因，运用VC6.0断点调试方法显示执行结果，说明该程序设计主要缺点。

   ```cpp
   #include <iostream>
   using namespace std;
   void fn1(); //函数声明，函数重载
   void fn1(int x);//值传递，若函数内改变值，不会改变外部实参x的值
   void fn2(int &x);//传引用，地址传送
   int x = 1;//全局变量
   int y = 2;//全局变量
   int main(){
     int x = 10;
     int y = 20;
     cout << "x = " << x << ",y = " << y << endl;//此时输出的是局部变量，利用就近原则
     fn1(x);//因为是值传递，所以并未修改x的值和y的值
     cout << "x = " << x << ",y = " << y << endl;//此时x和y依旧是局部变量的值
     fn2(x);//地址传递，会修改x的值
     cout <<"x = "<< x <<",y = " << y << endl;//此时x=30，y=20
     return 0;
   }
   void fn1(int x) //函数定义
   {
   int y = 100;
   cout << "x = " << x << ",y =" << y << endl;//输出的是传进来的x参数10和修改后的局部变量100
   }
   void fn2(int &x)
   {
   int y = 100;
   x=30;
   cout << "x = " << x << ",y =" << y << endl;//输出的是30，100
   }
   ```

   ![image-20230406161700913](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230406161700913.png)

2. 

   1. 编写C++程序，实现读入一篇英文文件，正确打印输出每一行的字数、对应的行号和总字数。

      ```cpp
      #include <iostream>
      #include <string>
      using namespace std;
      int main() 
      { 
       int i = 0, ans = 0;
       string s;
       FILE* stream1;
       freopen_s(&stream1,"1.in","r",stdin); 
       while (getline(cin, s))
       {
        cout << ++i << ":" << s.length() << endl;
        ans += s.length();
       }
       cout << "sum=" << ans;
       fclose(stdin);
       return 0; 
      } 
      ```

      ![image-20230406163342679](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230406163342679.png)

   2. 分析下面程序代码错误原因，进行运行调试，使得程序能够读入一篇英文文件，正确打印输出每一行的字数和对应的行号。要求报告中给出单步调试函数截图和步骤说明。

      ```cpp
      #include <iostream>
      #include <fstream>
      #include <string>
      using namespace std;
      void LetterCount(string line, int count);//将引用改为值传递
      //Nunber of letters in line is returned in count
      void LineCount(istream& f1le, int& count);
      //Nunber of lines in f1le is returned in count
      int main()
      {
      ifstream inFile;
      inFile.open("test.dat");
      int count = 0;
      LineCount(inFile, count);
      cout << "Number of lines: " << count << endl;
      return 0;
      }
      void LetterCount(string line,int count)
      {
      count = line.length();
      cout << " has " << count << " characters；" << endl;
      }
      void LineCount(istream& file, int& count)
      {
      string line;
      while (file)
      {
      getline(file, line);
      count++;
      cout << "Line " << count;
      LetterCount(line,count);
      }
      }
      ```

      ![image-20230406165343922](C:\Users\15989\AppData\Roaming\Typora\typora-user-images\image-20230406165343922.png)

3. 把飞机游戏代码按照实验内容3的方法，改成函数版本进行实现

   ```cpp
   #include <stdio.h>
   #include <stdlib.h>
   #include <conio.h>
   
   int main()
   {
   	int i, j;
   	int x = 5;
   	int y = 10;
   	char input;
   	int isFire = 0;
   
   	int ny = 5; // 一个靶子，放在第一行，ny列上
   	int isKilled = 0;
   
   	while (1)
   	{
   		system("cls");   // 清屏函数
   
   		if (!isKilled)  // 输出靶子
   		{
   			for (j = 0; j < ny; j++)
   				printf(" ");
   			printf("+\n");
   		}
   
   		if (isFire == 0) // 输出飞机上面的空行
   		{
   			for (i = 0; i < x; i++)
   				printf("\n");
   		}
   		else   // 输出飞机上面的激光竖线
   		{
   			for (i = 0; i < x; i++)
   			{
   				for (j = 0; j < y; j++)
   					printf(" ");
   				printf("  |\n");
   			}
   			if (y + 2 == ny)  // +2是因为激光在飞机的正中间，距最左边2个坐标
   				isKilled = 1; // 击中靶子
   			isFire = 0;
   		}
   
   		// 下面输出一个复杂的飞机图案
   		for (j = 0; j < y; j++)
   			printf(" ");
   		printf("  *\n");
   		for (j = 0; j < y; j++)
   			printf(" ");
   		printf("*****\n");
   		for (j = 0; j < y; j++)
   			printf(" ");
   		printf(" * * \n");
   
   
   		if (_kbhit())  // 判断是否有输入
   		{
   			input = _getch();  // 根据用户的不同输入来移动，不必输入回车
   			if (input == 'a')
   				y--;  // 位置左移
   			if (input == 'd')
   				y++;  // 位置右移
   			if (input == 'w')
   				x--;  // 位置上移
   			if (input == 's')
   				x++;  // 位置下移
   			if (input == ' ')
   				isFire = 1;
   		}
   	}
   	return 0;
   }
   ```

## 四、实验心得体会

学习的四重境界

知学、好学、会学、乐学
