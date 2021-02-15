using System;

namespace CSharp_21_02_15
{
    #region 02_15_first
    /*// 클래스 기반
    class Program
    {
        // static으로 잡아놔야 main에서 사용할 수 있다.
        static int a;
        static void f1()
        {
            Console.WriteLine("Hello World!");
        }
        // 진입점(Entry Point)
        // Main도 함수인데 누군가가 호출을 해야 한다.(OS 호출)
        // 운영체제가 객체를 생성시키는 일이 없기 때문에 static형태 사용해서 메모리 잡는다.
        // Main이 클래스 소속이다. 멤버 함수이다.
        static void Main(string[] args)
        {
            f1();
            a = 10;
        }
    }*/

    #endregion
    #region second
    /*class Program
    {   
        static void Main(string[] args)
        {
            // 클래스 기반.
            // Console은 객체 아니면 클래스 이다.
            Console.Write("1"); // 줄바꿈이 없다.
            Console.WriteLine("2"); // 캐리지 리턴이 있다.(CR) : 개행
            Console.Write("3"); // 줄바꿈이 없다.
            Console.WriteLine(); // 개행만 일어난다.

        }
    }*/
    #endregion
    #region
    class Program
    {
        
        static void Main(string[] args)
        {
    
            /*// %d == {0}
            Console.WriteLine("독 {0} 수 {1} 리", 10, 20);
            Console.WriteLine("독 {0:d4} 수 {1:D4} 리", 10, 20);
            Console.WriteLine("독 {0:x} 수 {1:x} 리", 10, 20);

            // type
            
            byte a01; // 0~255까지 사용 가능
            
            Console.WriteLine(byte.MaxValue);
            Console.WriteLine(byte.MinValue +" " + byte.MaxValue);
            

            sbyte a02; //
            Console.WriteLine(sbyte.MinValue + " " + sbyte.MaxValue);
            short a03;
            ushort a04;

            int a05;
            uint a06;

            long a07;
            ulong a08;

            char a09; // >> 2byte
            Console.WriteLine(sizeof(char));

            float a10 = 3.14f;
            double a11 = 3.14;

            bool a12 = true;

            decimal a13 = 3.14m;
            Console.WriteLine(sizeof(float));
            Console.WriteLine(sizeof(double));
            Console.WriteLine(sizeof(decimal));

            Console.WriteLine(long.MaxValue);
            int a = 10;
            Console.WriteLine(a);
            Console.WriteLine("a");
            Console.WriteLine("{a}");
            Console.WriteLine($"{a}"); // 제법 자주 나온다.
            Console.WriteLine($"a = {a}"); // 제법 자주 나온다.*/

            //char a = '호'; // 문자
            //string b = "랑이";
            //Console.WriteLine(a);
            //Console.WriteLine(b);
            //
            //object a = 10;// 모든 타입을 다 받아 준다.
            //object b = 3.14f;
            //object c = 3.14;
            //object d = true;
            //object e = '호';
            //object f = "랑이";
            //
            //Console.WriteLine(a.GetType());
            //Console.WriteLine(b.GetType());
            //Console.WriteLine(c.GetType());
            //Console.WriteLine(d.GetType());
            //Console.WriteLine(e.GetType());
            //Console.WriteLine(f.GetType());
            //
            // 문자열을 숫자로 변환(통신이 일어날때...)
            //string a = "1234";
            //int b = int.Parse(a);
            //Console.WriteLine( a + 10); // 문자열 + 숫자 = 문자열
            //Console.WriteLine( b + 10);
            //
            //// 숫자를 문자열로 변환()
            //int c = 5678;
            //string d = c.ToString();
            //Console.WriteLine(c + 10); 
            //Console.WriteLine(d + 10);
            //
            //string e = "" + c;
            //Console.WriteLine(e+10); // 실전에서 자주나온다.
            //
            //Console.Clear();

            // c#에서는 #define이 아닌 const 사용 권장.
            // enum : void위에 선언한다.

            string a = null;
            Console.WriteLine(a == null);
            int? b = null;
            Console.WriteLine(b == null);
        }
        
    #endregion
    }
}
