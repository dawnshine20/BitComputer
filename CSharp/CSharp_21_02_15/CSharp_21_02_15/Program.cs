using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using System.Threading.Tasks;

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
    #region third
    /*class Program
    { 
        static void Main(string[] args)
        {
            *//*// %d == {0}
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
            Console.WriteLine($"a = {a}"); // 제법 자주 나온다.*//*

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

            //string a = null;
            //Console.WriteLine(a == null);
            //int? b = null;
            //Console.WriteLine(b == null);
        }
    }*/
    #endregion
    #region 02_16
    //class Program
    //{
    //    //enum DialogResult
    //    //{
    //    //    YES,
    //    //    NO,
    //    //    CANCEL, 
    //    //    CONFIRM, 
    //    //    OK
    //    //}
    //
    //    static void Main(string[] args)
    //    {
    //        /*string a = null;
    //        Console.WriteLine( a == null );
    //
    //        int? b = null;
    //        Console.WriteLine( b == null );
    //
    //        string c = "10";
    //        var d = "20"; //  컴파일 시 타입이 결정된다. 결정 후 타입 변경 불가
    //
    //        object e = "10"; // 컴파일 시 타입이 결정된다. 결정 후 타입 변경 가능
    //        e = 1000; // 이 시점부터 int 타입이 된다.(런타임 동안 타입이 결정)
    //        dynamic f = "10"; // 런타임 시 타입이 결정된다.
    //                            // 실행될 때 타입이 결정된다. , 형이 안맞아도 컴파일 가능하다.*/
    //        //Console.WriteLine(c.GetType());
    //        //Console.WriteLine(d.GetType());
    //        //Console.WriteLine(e.GetType());
    //        //Console.WriteLine(f.GetType());
    //        //
    //        //Console.WriteLine(int.Parse(c));
    //        //Console.WriteLine(int.Parse(d));
    //        ////Console.WriteLine(int.Parse(e)); 사용불가
    //        //Console.WriteLine(int.Parse(f));
    //
    //        // 익셉션 발생
    //        //try
    //        //{
    //        //    string s3 = null;
    //        //    Console.WriteLine(s3.Length);
    //        //}
    //        //catch (Exception e) { Console.WriteLine("{0}", e); }
    //        //Console.WriteLine("-------------------------");
    //        //
    //        //int?[] ar = null;
    //        //Console.WriteLine(ar[0]);// 익셉션 발생
    //
    //        //int? a = null;
    //        //int? b = 0;
    //        //
    //        //Console.WriteLine(a ?? 10);// ?? 널 병합// 널이면 10 선택
    //        //Console.WriteLine(b ?? 10);// 널 아닐경우 b 소환
    //
    //        /*int[] ar = new int[5];
    //        int[] br = new int[] { 10, 20, 30 };
    //        Console.WriteLine(ar.Length);
    //        Console.WriteLine(br.Length);
    //
    //        int errNum1; // 성공 양수 실패 ( 음수 )
    //        uint errNum2; // 성공 양수 실패 0
    //
    //        // const int 예제 및 enum( 열겨형 ) >> #define을 묶어 놓은 것이다.
    //        DialogResult dr = DialogResult.OK;
    //
    //        int? a = null;
    //        Console.WriteLine(a.HasValue);
    //        a = 10;
    //        Console.WriteLine(a.Value);*/
    //
    //        // 문자열 다루기:"AppleBanana" >> CRUD
    //        //string s6 = "Tiger";
    //        //Console.WriteLine(s6.ToLower());
    //        //Console.WriteLine("Tiger".ToLower());
    //        //Console.WriteLine("Tiger".ToUpper());
    //        //
    //        //Console.WriteLine("=================");
    //        //string s1 = "Good Morning.";
    //        //// 1인수 : 시작 위치, 2인수 : 개수
    //        //Console.WriteLine(s1.Substring(0,6));
    //        //// 시작위치 부터 마지막까지
    //        //Console.WriteLine(s1.Substring(3));
    //        //
    //        //string[] ar = s1.Split(
    //        //    new string[] { " " },
    //        //    StringSplitOptions.None
    //        //    );
    //        //foreach (var item in ar)
    //        //{
    //        //    Console.WriteLine(item);
    //        //}
    //
    //        //Console.WriteLine(string.Format("{0}banana", "apple"));
    //        //// -는 좌측 +는 우측
    //        //Console.WriteLine(string.Format("{0, -10}banana", "apple"));
    //        //Console.WriteLine(string.Format("{0, 10}banana", "apple"));
    //        //
    //        //string fmt = "{0,-20 }{1,-15}{2, 30 }";
    //        //Console.WriteLine("{0}{1}", 100, 200);
    //        //
    //        //Console.WriteLine(fmt, "tiger", "호랑이", "서울");
    //        //Console.WriteLine(fmt, "lion", "사자", "부산");
    //        //Console.WriteLine(fmt, "eagle", "독수리", "대구");
    //
    //        string s = DateTime.Now.ToString("yyyy-MM-dd-HH-mm-ss");
    //        Console.WriteLine(s);
    //
    //        string year = DateTime.Now.ToString("yyyy");
    //        Console.WriteLine(year + "년");
    //
    //        string second = DateTime.Now.ToString("ss");
    //        Console.WriteLine(second + "초");
    //
    //        Console.WriteLine(DateTime.Now.DayOfWeek + "요일");
    //
    //        //ex1)
    //        string[] ss = new string[] { "일", "월", "화", "수", "목", "금", "토"  };
    //        int dw = (int)DateTime.Now.DayOfWeek;
    //        Console.WriteLine(ss[dw] + "요일");
    //
    //        //ex2)
    //        APPLE app = (APPLE)dw;
    //        Console.WriteLine(app + "요일");
    //
    //        //ex3)
    //        Console.WriteLine( (APPLE)DateTime.Now.DayOfWeek + "요일");
    //
    //        
    //        string name = "홍길동";
    //        int age = 10;
    //        //문자열 포맷
    //        Console.WriteLine("{0} {1}", name, age);
    //        string r = string.Format("{0} {1}", name, age);
    //        Console.WriteLine(r);
    //        // 문자열 보간
    //        Console.WriteLine($"{name} {age}");
    //        Console.WriteLine($"{name,-10} {age:D4}");
    //        Console.WriteLine($"{name} {age, -10:D4}");
    //        string rs = $"{name} "+ 
    //            $"{(age > 17 ? "성인":"미성년자")}";
    //        Console.WriteLine(rs);
    //
    //        name = "이순신";
    //        age = 20;
    //
    //        rs = $"{name} " +
    //            $"{(age > 17 ? "성인" : "미성년자")}";
    //        Console.WriteLine(rs);
    //    }
    //    enum APPLE { 일, 월, 화, 수, 목, 금, 토 }
    //}
    #endregion
    #region 02_17
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        //Random rand = new Random();
    //        //int num = rand.Next();
    //        //Console.WriteLine(num);
    //        //
    //        //for (int i = 0; i < 3; i++)
    //        //{
    //        //    Console.WriteLine(rand.Next() + " "); ;
    //        //}Console.WriteLine();
    //        //Console.WriteLine("{0, 10:n0}", rand.Next());
    //        //
    //        //for (int i = 0; i < 4; i++)
    //        //{
    //        //    Console.Write("{0}",rand.Next(5,10));
    //        //}Console.WriteLine();
    //        //// ex7) 0.0 ~ 1.0 >> color(0, 255)
    //        //for (int i = 0; i < 3; i++)
    //        //{
    //        //    Console.Write("{0:n3}", rand.NextDouble());
    //        //    Console.Write(" ");
    //        //}Console.WriteLine();
    //        //
    //        //// ex8) 0.0 ~ 10.0
    //        //Console.WriteLine(rand.NextDouble()*10);
    //        //Console.WriteLine();
    //        //
    //        //// ex9) n 개의 랜덤 데이터 생성
    //        //byte[] ar = new byte[10];
    //        //rand.NextBytes(ar);
    //        //foreach (var item in ar)
    //        //{
    //        //    Console.WriteLine(item + " ");
    //        //}Console.WriteLine();
    //
    //        //// 산술 > (대소)관계 > 논리
    //        //if(3+2 > 4 && 6-2 < 4)
    //        //{
    //        //}
    //        //// 컴파일러 자동 최적화 논리 적용
    //        //int a = 10;
    //        //if(true || a++ > 10)
    //        //{
    //        //    Console.WriteLine(a);
    //        //}
    //        //
    //        //bool c = true;
    //        //int d = 0;
    //        //int e = 1;
    //        //for (int i = 0; i < 10; i++)
    //        //{
    //        //    // 토글
    //        //    c = !c; 
    //        //    d = 1 - d;
    //        //    e = -e;
    //        //}
    //        // ?. (엘비스 : 널 조건부 연산)
    //        // 1. null 아니면 멤버값이 반환된다.
    //        // 2. 반환되기 때문에 대입 받을 수는 없다.
    //        int? tt;
    //        FOO foo1 = null;
    //        if (foo1 != null) {
    //            tt  = foo1.num;
    //        }
    //        // 위와 아래는 같은 동일한 문장이다.
    //        FOO foo2 = null;
    //        tt = foo2?.num;
    //        // null이기 때문에 f1() 호출하지 않는다.
    //        Console.WriteLine("=============");
    //        foo2?.f1();
    //        Console.WriteLine("=============");
    //        foo2 = new FOO();
    //        // null이 아니기 때문에 f1()호출
    //        foo2?.f1();
    //    }
    //    class FOO
    //    {
    //        public int num;
    //        public void f1()
    //        {
    //            Console.WriteLine(1);
    //        }
    //    }
    //}

    #endregion
    #region 드메레의 점수 문제
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Random rand = new Random();
    //        double a = 6, b = 4;
    //        double aWin = 0, bWin = 0;
    //        int num;
    //        for (int i = 0; i < 100000; i++)
    //        {
    //            a = 6;
    //            b = 4;
    //            while (true)
    //            {
    //                num = rand.Next(0 + 2);
    //                _ = ((num % 2) == 0) ? ++a : ++b;
    //                if (a == 7)
    //                {
    //                    ++aWin;
    //                    break;
    //                }
    //
    //                if (b == 7)
    //                {
    //                    ++bWin;
    //                    break;
    //                }
    //            }
    //        }
    //        Console.WriteLine("A:{0} B:{1}", aWin, bWin);
    //
    //    }
    #endregion
    #region 16진수 -> 2진수 공백포함시켜서 바꾸기
    //class Program
    //{
    //    static void f1(uint num)
    //    {
    //        uint q = num;
    //        uint[] r = new uint[100];
    //        int count = 0;
    //        while (q != 0)
    //        {
    //            r[count++] = q % 2; 
    //            q = q / 2;
    //        }
    //
    //        for (int i = 0; i <= count; i++)
    //        {
    //            if(i % 4 == 0 && i != 0)
    //                Console.Write(" ");
    //
    //            Console.Write("{0}", r[count - i]);
    //        }
    //        Console.WriteLine();
    //    }
    //    static void f234(int value)
    //    {
    //        string xnum = string.Format("{0:x}", value);                // 16진수 문자열로 변환.
    //        int xnumLen = xnum.Length;                                  // 문자열의 길이.
    //        for (int i = 0; i < xnumLen; i++)
    //        {
    //            string SubXNum = xnum.Substring(i, 1);                  // 문자를 하나 가져온다.
    //            string dNum = Convert.ToInt32(SubXNum, 16).ToString();  // 10진수 문자로 변환.
    //            int num = int.Parse(dNum);                              // int로 변환.
    //            int cnt = 0;        // 4자리 마다 띄어쓰기 위한 변수.
    //            string bnum = "";   // 2진수 문자열을 담을 변수.
    //            // 2진수 변환 작업.
    //            while (num != 0)
    //            {
    //                bnum += num % 2 != 0 ? 1 : 0;
    //                num = num / 2;
    //                ++cnt;
    //            }
    //            // 4자리 채우기 작업.
    //            while (cnt != 4)
    //            {
    //                bnum = bnum.Insert(bnum.Length, "0");
    //                ++cnt;
    //            }
    //            // 출력 코드.
    //            for (int j = 0; j < 4; j++)
    //            {
    //                Console.Write("{0}", bnum[3 - j]);
    //            }
    //            Console.Write(" ");
    //        }
    //    }
    //    static void f32(uint num)
    //    {
    //        int check;
    //        const int count = 32;
    //        for (int i = 0; i < count; i++)
    //        {
    //            check = 1 << (count - i - 1);
    //            if (i % 4 == 0 && i != 0)
    //                Console.Write(" ");
    //            Console.Write((num & check) == 0 ? 0 : 1);
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        // 0111 1011 1100 1101 0001 0010 0011 0100
    //        uint n = 0x7bcd1234;
    //        n = 0x7bcd123f;
    //        f1(n);
    //        f32(n);
    //    }
    //}
    #endregion
    #region 비트 연산자
    //class Program
    //{
    //    static void f32(uint num)
    //    {
    //        int check;
    //        const int count = 32;
    //        for (int i = 0; i < count; i++)
    //        {
    //            check = 1 << (count - i - 1);
    //            if (i % 4 == 0 && i != 0)
    //                Console.Write(" ");
    //            Console.Write((num & check) == 0 ? 0 : 1);
    //        }Console.WriteLine(" ");
    //    }
    //    static void Main(string[] args)
    //    {
    //        uint c = 10;
    //        uint d = c << 4; // c * 2^4 = c * 16 = 160
    //        uint e = c * 16; // c를 16번 더한다.
    //        Console.WriteLine(d);
    //        // c를 2021번 더한다.
    //        uint f = c * 2021;
    //        // 1024 + 512 + 256 + 128 + 64 + 32 + 4 + 1
    //        uint g = (c << 10) + (c << 9) + (c << 8) + (c << 7) + (c << 6) + (c << 5)
    //             + (c << 2) + (c << 0);
    //        Console.WriteLine(g);
    //
    //        uint n = 0x7bcd1234;
    //        uint h = n & 0x0000fff0;
    //        f32(h);
    //        
    //
    //        uint j1 = 0x00000001; // 비트가 상태값을 가진다. ( )
    //        uint j2 = 0x01000000; 
    //        uint j3 = 0x00040000; 
    //        uint j4 = j1 | j2 | j3;
    //        //uint j4 = j1 + j2 + j3; 특정 비트가 중복되었을 때 문제가 생긴다.
    //        f32(j4);
    //        uint k = ~n;
    //        Console.WriteLine();
    //        f32(n);
    //        f32(k);
    //        // xor
    //        uint l = n ^ 0xffffffff;
    //        Console.WriteLine();
    //        f32(n);
    //        f32(0xffffffff);
    //        f32(l);
    //
    //        int? a = null;
    //        // 널 병합 연산자
    //        // a가 null이면 100이 선택된다.
    //        Console.WriteLine( a ?? 100);
    //        a = 200;
    //        Console.WriteLine(a ?? 100);
    //        
    //    }
    //}
    #endregion
    #region 5장 제어문
    /*class MainApp
    {
        static void Main(string[] args)
        {
            //switch (){}
            //case 변수: 케이스에는 변수를 사용할 수 없다.
            //for(int i = 0; i < 10; i++)
            //for(int i = 1; i <= 10; i++)
            //for(int i = -5; i < 5; i++)
            int ct;
            int n = 10;
            for (ct = 0; ct < n; ct++, n+=20) ;
            Console.WriteLine(ct + " " + n);

            int[] ar = new int[4];
            int[] br = new int[4] { 1,2,3,4};
            foreach (var item in br)
            {
                Console.WriteLine(item);
            }
            
            for(int i = 0; i <3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    goto FIND;
                }
            }
        FIND:
            Console.WriteLine();

            var input = Console.ReadLine();
            Console.WriteLine(input.GetType());
            Console.WriteLine(input + 100);
            Console.WriteLine(int.Parse(input) + 100);
        }
    }*/
    #endregion
    #region 6장 함수
    //class MainApp
    //{
    //    static int a = 10;
    //    static ref int f1() 
    //    {
    //        return ref a;
    //    }
    //    static void f6 ( ref int x, ref int y )
    //    {
    //        int t = x;
    //        x = y;
    //        y = t;
    //    }
    //    // 참조형은 null값을 받을 수 없기 때문에 자동 방어적 프로그램으로써 작동
    //    // 주소상수로 사용되기 때문에 주소가 중간에 변할 염려가 없다.
    //    static void f2(int a, int b, out int q, out int r)
    //    {
    //        q = a / b;
    //        r = a % b;
    //    }
    //
    //    static void funcTest()
    //    {
    //        Console.WriteLine(1);
    //    }
    //    static void funcTest(int a)
    //    {
    //        Console.WriteLine(2);
    //    }
    //    static void funcTest(float a)
    //    {
    //        Console.WriteLine(3);
    //    }
    //    static void funcTest(params int[] args)
    //    {
    //        for (int i = 0; i < args.Length; i++)
    //        {
    //            Console.WriteLine(args[i]);
    //        }Console.WriteLine();
    //
    //        foreach (var item in args)
    //        {
    //            Console.WriteLine(item + " ");
    //        }Console.WriteLine();
    //    }
    //    static void f3(int a, int b)
    //    {
    //        Console.WriteLine(a + " " + b);
    //    }
    //
    //    static void Main(string[] args)
    //    {
    //        // ref 공유가 목적
    //        //int a = 3, b = 4;
    //        //f6(ref a, ref b);
    //        //Console.WriteLine(a + " " + b);
    //        int b = f1(); // 값이 리턴된다.(참조와 아무 관련이 없음)
    //        b = 20;
    //        Console.WriteLine(a + " " + b);
    //
    //        ref int c = ref f1(); // 공유가 일어 난다.
    //        c = 20;
    //        Console.WriteLine(a + " " + c);
    //
    //        Tiger t = new Tiger();
    //        int d = t.f1();
    //        d = 30;
    //        Console.WriteLine(t.a + " " + d);
    //
    //        ref int e = ref t.f1();
    //        e = 40;
    //        Console.WriteLine(t.a + " " + e);
    //
    //        // out 목적은 결과를 얻기 위한 공유
    //        f2(10, 3, out int q2, out int r2);
    //        Console.WriteLine(q2 + " " + r2);
    //        Console.WriteLine($"q2:{q2} r2:{r2}");
    //        Console.WriteLine("q2:{0} r2:{1}",q2,r2);
    //
    //        //함수 재정의(오버로딩) : 동일한 이름으로 함수 생성 조건
    //        // 1. 전달 이수 개수가 다를 때
    //        // 2. 개수가 같더라도 전달 타입이 다를때
    //        // 3. 리턴 타입은 오버로딩 조건에 포함되지 않는다.
    //        funcTest();
    //        funcTest((int)10);
    //        funcTest((float)10.0f);
    //        funcTest(10, 20, 30);
    //        // 명명된 매개변수 
    //        // 코드의 가독성을 높인다. (작은 의미)
    //        // 특정 매개변수 값 바꿈
    //        f3(a: 100, b: 200);
    //        f3(b: 100, a: 200);
    //
    //        Test te = new Test();
    //        te.func1();
    //    }
    //}
    //
    //class Tiger
    //{
    //    public int a = 10;
    //    public ref int f1()
    //    {
    //        return ref a;
    //    }
    //}
    //
    //class Test
    //{
    //    public void func1()
    //    {
    //        Console.WriteLine(1);
    //        //지역함수
    //        // 호출된 함수 안에서만 사용할 수 있다.
    //        // 사용하고 버리는 함수
    //        // 호출 위치와는 상관 없다.
    //        // 지역적인 반복코드를 묶어놓고 사용한다.(좁은 의미)
    //        // 람다 함수를 성립시키기 위해 사용(큰 의미)
    //        //람다 함수 용도 : 함수에 인수 전달로 숫자, 문자열 등등
    //        // + 알파(코드 전달)
    //        func2();
    //        void func2() // 일반 함수, 함수
    //        {
    //            Console.WriteLine(2);
    //        }
    //
    //        //실예)
    //        //func3( func2() )
    //        //{
    //        //        func2();
    //        //}
    //    }
    //}
    #endregion
    #region 7장 클래스
    //class Global
    //{
    //    public static int ct = 0;
    //}
    //class ClassA
    //{
    //    public ClassA()
    //    {
    //        Global.ct++;
    //    }
    //}
    //class ClassB
    //{
    //    public ClassB()
    //    {
    //        Global.ct++;
    //    }
    //}
    //class Program
    //{    
    //    class Tiger
    //    {
    //        public Tiger()
    //        {
    //            Console.WriteLine("생성자 호출");
    //        }
    //
    //        public Tiger(int a, int b)
    //        {
    //            this.a = a; // 객체.a = 인수 a
    //            this.b = b; // 객체.b = 인수 b
    //        }
    //
    //        public int a,b;
    //    
    //        public Tiger f1()
    //        {
    //            Console.WriteLine(a + " " + b);
    //            Console.WriteLine("f1"); ;
    //            return this;
    //        }
    //
    //        public Tiger f2()
    //        {
    //            Console.WriteLine("f2");
    //            //새롭게 객체 생성
    //            Tiger t = new Tiger();
    //            t.a = this.a;
    //            t.b = this.b;
    //            // 새로운 객체 반환
    //            return t;
    //        }
    //    }
    //
    //    static void Main(string[] args)
    //    {
    //        //Tiger t1 = new Tiger();
    //        //Tiger t2 = new Tiger();
    //        ////t1, t2 객체의 메소드는 서로 공유된다.
    //        //t1.f1();
    //        //t2.f1();
    //        //-------
    //        //new ClassA();
    //        //new ClassB();
    //        //new ClassB();
    //        //Console.WriteLine(Global.ct++);
    //        //--------
    //        Tiger t1 = new Tiger();
    //        t1.a = 10;
    //        t1.b = 20;
    //        
    //        // 값을 복사하려고 한 것인데, 메모리 공유가 되어 버렸다.(Shallow Copy가 일어났다)
    //        // C#에서는 C++과 달리 Deep Copy를 할 수 있는 복사 생성자가 없다.
    //        Tiger t2 = t1;
    //        t1.a = 30;
    //        t1.b = 40;
    //        Console.WriteLine(t1.a + " " + t1.b);
    //        Console.WriteLine(t2.a + " " + t2.b);
    //
    //        // deep copy를 원한다면 직접 만들어줘야한다.
    //        Tiger t3 = t1.f2();
    //        t3.a = 50;
    //        t3.b = 60;
    //
    //        Console.WriteLine(t1.a + " " + t1.b);
    //        Console.WriteLine(t3.a + " " + t3.b);
    //
    //        Tiger t = new Tiger();
    //        t.f1().f2();
    //    }
    //}
    //------------------------------------------------------------
    //class classA
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1);
    //        classB bb = new classB();
    //        bb.f2(this); // >> 다른 객체에게 자신의 객체의 주소를 보낸다.
    //    }
    //    public void f3()
    //    {
    //        Console.WriteLine(3);
    //    }
    //}
    //
    //class classB
    //{
    //    public void f2(classA @object)
    //    {
    //        Console.WriteLine(2);
    //        @object.f3();
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        classA t = new classA();
    //        t.f1();
    //    }
    //}
    //------------------------------------
    //class Tiger
    //{
    //    public int a, b;
    //
    //    public Tiger()
    //    {
    //        Console.WriteLine(0);
    //    }
    //
    //    public Tiger(int a) : this()// this()는 생성자를 콜 시킨다.
    //    {
    //        Console.WriteLine(1);
    //        this.a = a;
    //    }
    //    public Tiger(int a, int b) : this(a)
    //    {
    //        Console.WriteLine(2);
    //        //this.a = a;
    //        this.b = b;
    //    }
    //    public void output()
    //    {
    //        Console.WriteLine(a + "," + b);
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger t1 = new Tiger(10);
    //        t1.output();
    //        Console.WriteLine("=========");
    //        Tiger t2 = new Tiger(10, 20);
    //        t2.output();
    //    }
    //}
    //----------------상속
    // 객체지향의 3대 특성 : 상속, 다형성, 데이터은닉
    //class Apple // 기반 클래스
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1);
    //    }
    //    public void f3()
    //    {
    //        Console.WriteLine("부 f3");
    //    }
    //}
    //class Banana : Apple // 파생클래스
    //{
    //    public void f2()
    //    {
    //        Console.WriteLine(2);
    //    }
    //    public void f3()
    //    {
    //        Console.WriteLine("자 f3");
    //    }
    //    public void f4()
    //    {
    //        base.f3();
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Banana b = new Banana();
    //        b.f1();
    //        b.f2();
    //        b.f3();
    //        b.f4();
    //        //b.Apple::f3() <- c++에서 부모 함수를 사용할 수 있다.
    //    }
    //}
    //-----------------------------------
    //class Apple // 기반 클래스
    //{
    //    public Apple()
    //    {
    //        Console.WriteLine(1);
    //    }
    //    public Apple(int a)
    //    {
    //        Console.WriteLine(2);
    //    }
    //}
    //class Banana : Apple // 파생클래스
    //{
    //    public Banana()
    //    {
    //        Console.WriteLine(3);
    //    }
    //    public Banana(int a): base()        
    //    {
    //        
    //        Console.WriteLine(4);
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Banana b = new Banana(100);
    //    }
    //}
    //--------------------------------
    //class A { public void f1() { Console.WriteLine(1); } }
    //class B: A { public void f2() { Console.WriteLine(2); } }    
    //class C: A { public void f3() { Console.WriteLine(3); } }
    //
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        A a = new B(); //부자 >> 업캐스팅
    //        //is 확인용도 
    //        if (a is B)
    //        {
    //            //방법1
    //            ((B)a).f2();
    //
    //            //방법2
    //            B b = (B)a; // 자 = 부(다운 캐스팅)
    //            b.f2();
    //
    //            Console.WriteLine(4);
    //        }
    //
    //
    //        A a1 = new C(); // 부자 >> 업캐스팅
    //        //제대로 사용한 경우
    //        C c = a1 as C; // C타입이 맞으면 C타입으로 반환
    //        if(c != null)
    //        {
    //            c.f3();
    //            Console.WriteLine("not null");
    //        }
    //        
    //        // 잘못 사용하고 있는 경우
    //        B d = a1 as B; // B타입이 아니라면 NULL 반환
    //        if(d == null)
    //        {
    //            Console.WriteLine("null");
    //        }
    //
    //        // 예외 상황이 발생한다.
    //        // B e = (B)a1;
    //        // is는 true/false // as는 null
    //        
    //    }
    //}
    //-----------------------------------
    /*class Apple
    {
        public void f1()
        {
            Console.WriteLine(1); ;
        }
        public virtual void f2()
        {
            Console.WriteLine(2);
        }
    }
    class Banana:Apple
    {
        public void f1()
        {
            Console.WriteLine(3); 
        }
        public override void f2()
        {
            Console.WriteLine(4);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Banana t1 = new Banana();
            t1.f1();
            t1.f2();

            Apple t2 = new Banana();
            t2.f1();
            t2.f2();
        }
    }*/
    //----------------------------------
    //class Apple
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1); 
    //    }
    //    public virtual void f2()
    //    {
    //
    //    }
    //}
    //class Banana : Apple
    //{
    //    public override void f2()
    //    {
    //        Console.WriteLine("banana");
    //    }
    //}
    //class Orange : Apple
    //{
    //    public override void f2()
    //    {
    //        Console.WriteLine("orange");
    //    }
    //}
    //class Program
    //{
    //    //static void f1(Apple a)
    //    //{
    //    //    a.f2();
    //    //}
    //    //static void Main(string[] args)
    //    //{
    //    //    //오버라이드 된것 선택적으로 함수 호출
    //    //    f1(new Banana());
    //    //    f1(new Orange());
    //    //
    //    //    Apple[] ar = new Apple[] { new Banana(), new Orange() };
    //    //    //rnd
    //    //    Random rand = new Random();
    //    //    int num = rand.Next(2);
    //    //    ar[num].f2();
    //    //}
    //}
    //------------------------------
    //class A
    //{
    //    public virtual void f1()
    //    {
    //        Console.WriteLine(1); 
    //    }
    //    
    //}
    //class B : A
    //{
    //    public override void f1()
    //    {
    //        Console.WriteLine(2);
    //    }
    //}
    //class C : B
    //{
    //    public override void f1()
    //    {
    //        Console.WriteLine(3);
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        A a = new C();
    //        a.f1();
    //    }
    //}
    //---------------------------------------------
    //class Aaa
    //{
    //    // List<int> li = new List<int>();
    //    List<Bbb> li = new List<Bbb>();
    //    public void f1(string s1, string s2)
    //    {
    //        Bbb t = new Bbb();
    //        t.f2(this, s1, s2);
    //    }
    //    public void showData()
    //    {
    //        foreach (var data in li)
    //        {
    //            Console.WriteLine(data.getItem() + " " + data.getValue());
    //        }
    //    }
    //    public void showData(string item)
    //    {
    //        foreach (var data in li)
    //        {
    //            if (data.getItem() == item)
    //            {
    //                Console.WriteLine(data.getValue());
    //            }
    //        }
    //    }
    //    class Bbb
    //    {
    //        private string item;
    //        public string getItem() { return item; }
    //        private string value;
    //        public string getValue() { return value; }
    //
    //        //flag변수를 쓰면 스파게티 코드가 생성되므로\
    //        // 함수로 만든 케이스
    //        private void find(Aaa thiscf, string ite)
    //        {
    //            for (int i = 0; i < thiscf.li.Count; i++)
    //            {
    //                if (thiscf.li[i].item == item)
    //                {
    //                    thiscf.li[i] = this;
    //                    //found = true;
    //                    return;
    //                }
    //                thiscf.li.Add(this);
    //            }
    //        }
    //        public void f2(Aaa thiscf, string item, string value)
    //        {
    //            this.item = item;
    //            this.value = value;
    //            Console.WriteLine(thiscf.li.Count);
    //
    //            find(thiscf, item);
    //
    //            //bool found = false; // flag변수는 스파게티 코드의 원인
    //            
    //            /*if (found == false)
    //            {
    //                thiscf.li.Add(this);
    //            }*/
    //        }
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Aaa aaa = new Aaa();
    //        aaa.f1("Version", "5.0");
    //        aaa.f1("Size", "5000");
    //        aaa.f1("Price", "400000");
    //        aaa.f1("Date", "12월20일");
    //        //
    //        aaa.f1("Size", "8000");
    //        aaa.f1("Version", "7.0");
    //        aaa.showData();
    //        aaa.showData("Size");
    //    }
    //}
    //-------------------------------------
    //---setter,getter
    //class Tiger
    //{
    //    private string name;
    //    private int age;
    //    public void setName(string name){ this.name = name; }
    //    public void setAge(int age) { this.age = age; }
    //    public string getName(){ return name; }
    //    public int getAge(){ return age; }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger t = new Tiger();
    //        t.setAge(100);
    //        Console.WriteLine(t.getAge());
    //    }
    //}
    //------------------------
    ////- setter, getter 진화버젼
    //class Tiger
    //{
    //    private string name;
    //    public string Name { // Property
    //        get { return name; }
    //        set { name = value; }
    //    }
    //    public int Age { set; get; }
    //    
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger t = new Tiger();
    //        t.Name = "tiger";
    //        Console.WriteLine(t.Name);
    //    }
    //}
    //-------------------------------
    //partial class Tiger
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1);
    //    }
    //}
    //partial class Tiger
    //{
    //    public void f2()
    //    {
    //        Console.WriteLine(1);
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //    }
    //}
    //-------------------------------
    ////확장 메소드
    //public static class A
    //{
    //    public static void f1(this int a, int b)
    //    {
    //        Console.WriteLine(a + " " + b);
    //    }
    //    public static void power(this int a, int b)
    //    {
    //        int result = 1;
    //        for(int i = 0; i < b; i++)
    //        {
    //            result *= a;
    //        }
    //        Console.WriteLine(result);
    //    }
    //}
    //
    //public static class B
    //{
    //    public static void f2(this string a)
    //    {
    //        Console.WriteLine(a);
    //    }
    //    
    //}
    //class Program
    //{   
    //    static void Main(string[] args)
    //    {
    //        3.f1(100);
    //        int num = 200;
    //        // 추가 메소드를 만들어서 사용하는 것이 목적
    //        num.f1(300);
    //
    //        // 표준 멤버 함수는 익혀서 사용
    //        //num안에 들어 있는 나의 함수를 만들어 보자
    //        string s = num.ToString();
    //        Console.WriteLine(s);
    //
    //        int a = 3;
    //        a.power(4);
    //
    //        "test".f2();
    //        string s1 = "Hello World";
    //        s1.f2();
    //    }
    //}
    //---------------------------------------------
    ////c#의 구조체
    //struct STRU // 함수 안쓰고 데이터만 넣는 경우에만 사용
    //{
    //    public int a;
    //    public int b;
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        // new 키워드가 필요 없다.
    //        STRU s1;
    //        s1.a = 10;
    //        s1.b = 10;
    //
    //        // tuple
    //        int a = 10;
    //        var b = (10, 20, 30, 40);
    //        // 참고 : tuple = (), list(배열) = [], 딕셔너리 = {}
    //        Console.WriteLine(b.Item1 + " " + b.Item4);
    //
    //        var c = ("호랑이", 100);
    //        Console.WriteLine(c);
    //
    //        var d = (name : "호랑이", age : 100);
    //        Console.WriteLine(d);
    //        Console.WriteLine(d.Item1 + " " + d.Item2);
    //        Console.WriteLine(d.name + " " + d.age);
    //
    //        var e = d;
    //        Console.WriteLine(e);
    //
    //        // 중요하다.
    //        var (n, t) = d; // 데이터 분해
    //        Console.WriteLine(n + " " + t);
    //    }
    //}
    #endregion
    #region 8장 인터페이스
    //class Program
    //{
    //    interface ILogger
    //    {
    //        void WriteLog(string message);
    //    }
    //    class ConsoleLogger : ILogger
    //    {
    //        public void WriteLog(string message)
    //        {
    //            Console.WriteLine(message);
    //        }
    //    }
    //    class FileLogger : ILogger
    //    {
    //        private StreamWriter writer;
    //        //생성자를 통해 .txt 저장할 경로 설정
    //        public FileLogger(string path)
    //        {
    //            // File *fpt = fopen(" sample.txt",  "rb");
    //            writer = File.CreateText(path);
    //            writer.AutoFlush = true; //남아있는 쓰래기를 지워달라는 코드
    //        }
    //
    //        public void WriteLog(string message)
    //        {
    //            writer.WriteLine("{0}, {1}",DateTime.Now.ToShortDateString(), message);
    //        }
    //    }
    //    //class PrintLogger : iLogger
    //    class ClimateMonitor
    //    {
    //        private ILogger logger;
    //        public ClimateMonitor(ILogger logger)
    //        {
    //            this.logger = logger;
    //        }
    //        public void start()
    //        {
    //            while(true)
    //            {
    //                Console.WriteLine("온도를 입력해 주세요.");
    //                string temperature = Console.ReadLine();
    //                if (temperature == "")
    //                    break;
    //
    //                logger.WriteLog("현재온도 : " + temperature);
    //            }
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        //ClimateMonitor climateMonitor = new ClimateMonitor(new FileLogger("test01.txt"));
    //        //climateMonitor.start();
    //        ClimateMonitor climateMonitor = new ClimateMonitor(new ConsoleLogger());
    //        climateMonitor.start();
    //    }
    //}
    //-------------------------------------
    //interface ILoggerA
    //{
    //    void f1();
    //}
    //interface ILoggerB:ILoggerA
    //{
    //    void f2();
    //}
    //class Tiger : ILoggerB
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1);
    //    }
    //
    //    public void f2()
    //    {
    //        Console.WriteLine(2);
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger t = new Tiger();
    //        t.f1();
    //        t.f2();
    //    }
    //}
    //-------------------------------------
    //interface ILoggerA
    //{
    //    void fly();
    //}
    //interface ILoggerB
    //{
    //    void run();
    //}
    //class Tiger : ILoggerA, ILoggerB
    //{
    //    public void fly()
    //    {
    //        Console.WriteLine("1");
    //    }
    //
    //    public void run()
    //    {
    //        Console.WriteLine("2");
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger t = new Tiger();
    //        t.fly();
    //        t.run();
    //
    //        ILoggerA r1 = t as ILoggerA;
    //        r1.fly();
    //
    //        ILoggerB r2 = t as ILoggerB;
    //        r2.run();
    //    }
    //}
    //---------------------------------------
    //Tiger를 이용해서 객체를 생성시킬 수 있는가? 
    //->안된다. f2 구현이 아직 안되어있기 때문이다.(즉,상속 용도로만 사용 가능하다.)
    //abstract class Tiger
    //{
    //    public void f1()
    //    {
    //        Console.WriteLine(1);
    //    }
    //    public abstract void f2();
    //}
    //class Lion : Tiger
    //{
    //    public override void f2()
    //    {
    //        Console.WriteLine(2);
    //    }
    //}
    //
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Tiger lion = new Lion();
    //        lion.f1();
    //        lion.f2();
    //
    //    }
    //}
    #endregion
    #region 9장 프로퍼티
    //class BirthdayInfo
    //{
    //    private string name;
    //    public string Name
    //    {
    //        get{return name;}
    //        set{this.name = value;}
    //    }
    //
    //    private DateTime birthday;
    //    public DateTime Birthday
    //    {
    //        get { return birthday; }
    //        set { this.birthday = value; }
    //    }
    //    
    //    public int Age
    //    {
    //        get
    //        {
    //            Console.WriteLine("----------------------");
    //            Console.WriteLine(DateTime.Now);
    //            Console.WriteLine(DateTime.Now.Subtract(birthday));
    //            Console.WriteLine(DateTime.Now.Subtract(birthday).Ticks);
    //            return new DateTime(DateTime.Now.Subtract(birthday).Ticks).Year;
    //        }
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        BirthdayInfo birth = new BirthdayInfo();
    //        birth.Name = "홍길동";
    //        birth.Birthday = new DateTime(1991, 6, 28);
    //        Console.WriteLine(birth.Name);
    //        Console.WriteLine(birth.Birthday);
    //        Console.WriteLine(birth.Age);
    //    }
    //}
    //-------------------------------------
    //class Tiger
    //{
    //    private int a;
    //    public int A
    //    {
    //        get { return a; }
    //        set { a = value; }
    //    }
    //    private int b;
    //    public int B
    //    {
    //        get { return b; }
    //        set { b = value; }
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        // 원래 public문법일 때 사용 가능하던 것을 private로 바꾸면서 Property를 이용하게 되었다.
    //        Tiger t = new Tiger() { A = 10, B = 20 };
    //        Console.WriteLine(t.A + " " + t.B);
    //
    //        //익명 클래스 혹은 무명 클래스
    //        var obj = new { Name = "홍길동", Age = 30 };
    //        Console.WriteLine(obj.Name);
    //        Console.WriteLine(obj.Age);
    //        //변수가 상수화 된다.
    //        //obj.Age = 100;<<----------불가능
    //
    //        
    //        var b = new { Subject = "수학", Scores = new int[] { 1, 2, 3, 4 } };
    //        Console.WriteLine(b.Subject);
    //        
    //        foreach (var item in b.Scores)
    //        {
    //            Console.Write(item + " ");
    //        }Console.WriteLine();
    //        // 인터페이스 안의 필드로 프라퍼티 설정 할 수 있다.
    //    }
    //}
    //-------------------------------------------------
    //interface ITiger
    //{
    //    // 이 변수는 무조건 상속 받아서 정의 하세요.
    //    int Num
    //    {
    //        get;
    //        set;
    //    }
    //}
    //class ILion : ITiger
    //{
    //    private int num;
    //    public int Num {
    //        get { return num; }
    //        set { num = value; } 
    //    }
    //}
    //
    //abstract class Cat
    //{
    //    abstract public int Num
    //    {
    //        get;
    //        set;
    //    }
    //}
    //
    //class Dog : Cat
    //{
    //    public override int Num { get ; set ; }
    //}
    //
    //class Program
    //{
    //    static void Main(string[] args)
    //    { 
    //    }
    //}
    #endregion
    #region 10장 배열 및 컬렉션
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        
    //        ////3.
    //        //int[] cr = { 1, 2, 3 };
    //        //
    //        //foreach(var item in cr)
    //        //{
    //        //    Console.WriteLine(item + " ");
    //        //}Console.WriteLine();
    //        //
    //        ////4.
    //        //string[] dr = new string[] { "호랑", "코끼", "독수" };
    //        //------------------------------------------------------------
    //        //-----------------------------------
    //        int[] scores = new int[] { 80, 74, 81, 90, 34 };
    //        foreach (var item in scores)
    //        {
    //            Console.Write(item + " ");
    //        }Console.WriteLine();
    //
    //        //Array.Sort(scores);
    //        //foreach (var item in scores) { Console.Write(item + " "); }
    //        //Console.WriteLine();
    //        //
    //        Console.WriteLine("===================1");
    //        //// 이진 검색 : 못찾으면 -1 리턴
    //        //// 정렬이 되어있다는 가정하에 검색해야 한다.
    //        //int a = Array.BinarySearch<int>(scores, 34);
    //        //Console.WriteLine(a);
    //
    //        //검색을 처음부터 찾는것
    //        //정렬 비용이 없고 검색이 느리다.
    //        Console.WriteLine(Array.IndexOf(scores, 34));
    //
    //
    //        Console.WriteLine("===================2");
    //        // 조건을 줄테니 모두 참인지 확인하라
    //        Console.WriteLine(Array.TrueForAll<int>(scores, f1));
    //
    //        // 조건을 줄테니 조건을 만족하는 첫번째 수의 인덱스를 출력하라
    //        Console.WriteLine(Array.FindIndex<int>(scores, f2));
    //        //Console.WriteLine(Array.FindIndex<int>(scores, 
    //        //    delegate(int n) 
    //        //    {
    //        //        return (n < 75) ? true : false;
    //        //    }
    //        //));
    //
    //        Console.WriteLine("===================3");
    //        Array.Resize<int>(ref scores, 10);
    //        Console.WriteLine(scores.Length);
    //
    //        foreach (var item in scores) { Console.Write(item + " "); }
    //        Console.WriteLine();
    //
    //        // 1번째 원소 ~ 3번째 원소까지 0으로 초기화 해라
    //        Array.Clear(scores, 1, 3);
    //        foreach (var item in scores) { Console.Write(item + " "); }
    //    }
    //
    //    public static bool f1(int n)
    //    {
    //        return (n > 33) ? true : false;
    //    }
    //    public static bool f2(int n)
    //    {
    //        return (n < 80) ? true : false;
    //    }
    //}
    //-------------------------------------------
    //class Program
    //{
    //    static void PrintArr(int[,] array, int angle)
    //    {
    //        int row;
    //        int col;
    //        int what = angle / 90;
    //
    //        if (what == 0 || what == 2)
    //        { row = 3; col = 4; }
    //        else if (what == 1 || what == 3)
    //        { row = 4; col = 3; }
    //        else return;
    //
    //        for (int i = 0; i < row; i++)
    //        {
    //            for (int j = 0; j < col; j++)
    //            {
    //                //Console.Write("[{0},{1}] ", i, j);
    //                Console.Write(array[i, j] + " ");
    //            }
    //            Console.WriteLine();
    //        }
    //    }
    //    //static int[,] RotateArr (int[,] array, int angle)
    //    //{
    //    //    int row;
    //    //    int col;
    //    //    int what = angle / 90;
    //    //
    //    //    if (what == 0 || what == 2)
    //    //    { row = 3; col = 4; }
    //    //    else if (what == 1 || what == 3)
    //    //    { row = 4; col = 3; }
    //    //    else return null;
    //    //
    //    //    if (what == 1)
    //    //        ;
    //    //    else if (what == 2)
    //    //        ;
    //    //    else if (what == 3)
    //    //        ;
    //    //    else return null;
    //    //
    //    //    return array;
    //    //}
    //    static void Main(string[] args)
    //    {
    //        int[,] ar = new int[3, 4];//{
    //        //    { 1, 2, 3, 4 },
    //        //    { 5, 6, 7, 8 },
    //        //    { 9, 10, 11, 12 }
    //        //}; // 세로, 가로
    //        PrintArr(ar, 0);
    //        Console.WriteLine();
    //
    //        int[,] br = new int[4, 3];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 4; j++)
    //            {
    //                br[j, 2 - i] = ar[i, j];
    //            }
    //        }
    //        PrintArr(br, 90);
    //        Console.WriteLine();
    //
    //        int[,] cr = new int[3, 4];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 4; j++)
    //            {
    //                cr[2 - i, 3 - j] = ar[i, j];
    //            }
    //        }
    //        PrintArr(cr, 180);
    //        Console.WriteLine();
    //
    //        int[,] dr = new int[4, 3];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 4; j++)
    //            {
    //                dr[3 - j, i] = ar[i, j];
    //            }
    //        }
    //        PrintArr(dr, 270);
    //        Console.WriteLine();
    //    }
    //}
    //--------------------------------------------------
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        int[,,] ar = new int[2,3,4] {
    //            { 
    //                { 1, 2, 3, 4},
    //                { 1, 2, 3, 4},
    //                { 1, 2, 3, 4} 
    //            },
    //            { 
    //                { 1, 2, 3, 4},
    //                { 1, 2, 3, 4},
    //                { 1, 2, 3, 4}
    //            }
    //        };
    //        Console.WriteLine(ar.GetLength(0)); // 2
    //        Console.WriteLine(ar.GetLength(1)); // 3
    //        Console.WriteLine(ar.GetLength(2)); // 4
    //
    //        //for (int i = 0; i < ar.GetLength(0); i++)
    //        //{
    //        //    for (int j = 0; j < ar.GetLength(1); j++)
    //        //    {
    //        //        Console.Write("[{0}, {1}]", i, j);
    //        //    }
    //        //}
    //        Console.WriteLine();
    //        
    //        for (int i = 0; i < ar.GetLength(0); i++)
    //        {
    //            for (int j = 0; j < ar.GetLength(1); j++)
    //            {
    //                for (int k = 0; k < ar.GetLength(2); k++)
    //                {
    //                    Console.Write(ar[i, j, k] + " ");
    //                }Console.WriteLine();
    //            }Console.WriteLine();
    //        }Console.WriteLine();
    //
    //    }
    //}
    //--------------------------------------------------------------
    //class Program
    //{
    //    static void PrintArr(int[,,] array, int angle, int num)
    //    {
    //        int row ;
    //        int col ;
    //        int what = angle / 90;
    //
    //        if (what == 0 || what == 2)
    //        { row = 3; col = 3; }
    //        else if (what == 1 || what == 3)
    //        { row = 3; col = 3; }
    //        else return;
    //
    //        for (int j = 0; j < row; j++)
    //        {
    //            for (int k = 0; k < col; k++)
    //            {
    //                //Console.Write("[{0},{1}] ", i, j);
    //                Console.Write(array[num, j, k] + " ");
    //            }
    //            Console.WriteLine();
    //        }
    //        Console.WriteLine();
    //    }
    //    static void Main(string[] args)
    //    {
    //        int num = 0;
    //        int[,,] ar = new int[4, 3, 3] {
    //            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
    //            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
    //            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
    //            { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }
    //        };
    //        PrintArr(ar, 0, num);
    //
    //        //세로, 가로
    //        Console.WriteLine();
    //        num = 1;
    //        int[,,] br = new int[4, 3, 3];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 3; j++)
    //            {
    //                br[num, j, 2 - i] = ar[num, i, j];
    //            }
    //        }
    //        PrintArr(br, 90, num);
    //
    //        Console.WriteLine();
    //        num = 2;
    //        int[,,] cr = new int[4, 3, 3];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 3; j++)
    //            {
    //                cr[num, 2 - i, 2 - j] = ar[num, i, j];
    //            }
    //        }
    //        PrintArr(cr, 180, num);
    //
    //        Console.WriteLine();
    //        num = 3;
    //        int[,,] dr = new int[4, 3, 3];
    //        for (int i = 0; i < 3; i++)
    //        {
    //            for (int j = 0; j < 3; j++)
    //            {
    //                dr[num, 2 - j, i] = ar[num, i, j];
    //            }
    //        }
    //        PrintArr(dr, 270, num);
    //
    //        //dr[3 - j, i] = ar[i, j];
    //    }
    //}
    //------------------ 가변 배열
    //int p1[3][4];
    //int* p1[3]; (가로길이 모름)
    //int** p1; // 가로, 세로 길이 모름
    //int (*p1)p1[4]; 세로길이 모름
    // ex)
    // int* p1[3];
    // p1[0] = new int[3];
    // p1[1] = new int[4];
    // p1[2] = new int[5];
    //
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        // 세로길이만 알고있음
    //        int[][] ar = new int[3][];
    //        ar[0] = new int[3] { 0, 1, 2 };
    //        ar[1] = new int[4] { 3, 4, 5, 6 };
    //        ar[2] = new int[5] { 7, 8, 9, 8, 7 };
    //        Console.WriteLine(ar[0][0]);
    //        Console.WriteLine(ar[2][4]);
    //        // jagged array 배열이 들쑥날쑥하다
    //        foreach (int[] item in ar)
    //        {
    //            foreach (int data in item)
    //            {
    //                Console.Write(data + " ");
    //            }Console.WriteLine();
    //        }
    //        int a = 3, b = 3, c=4, d = 5;
    //        int[][] br = new int[a][];
    //        br[0] = new int[b];
    //        br[1] = new int[c];
    //        br[2] = new int[d];
    //    }
    //}
    //---------------------------------
    //---------------컬렉션
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Stack s = new Stack();
    //        s.Push(1);
    //        s.Push(2);
    //
    //        // 반환형이 object 타입이므로 (int)로 형변환 필요
    //        int num = (int)s.Pop();
    //        Console.WriteLine("pop : " + num);
    //
    //        Console.WriteLine();
    //        foreach (var item in s)
    //        {
    //            Console.WriteLine(item + " ");
    //        }
    //        //-----------------------------------
    //        Hashtable ht = new Hashtable();
    //        ht[0] = "호랑이";
    //        ht[1] = "코끼리";
    //        ht[2] = "독수리";
    //        ht["하나"] = "소나무";
    //        ht["둘"] = "향나무";
    //        ht["셋"] = "마오카이";
    //        ht.Add("넷", "왕나무");
    //        Console.WriteLine(ht[1] + " " + ht["둘"]);
    //
    //        foreach (DictionaryEntry item in ht)
    //        {
    //            Console.WriteLine(item.Key + " " + item.Value);
    //        }
    //        Console.WriteLine(ht.Count + "개");
    //        //--------------------------------------
    //        int size = 3;
    //        int[] ar = new int[size];
    //        // 파일 리딩 혹은 다른 메모리에서 복사 받음
    //        ar[0] = 10; ar[1] = 20; ar[2] = 30;
    //
    //        ArrayList a = new ArrayList(ar);
    //        Stack b = new Stack(ar);
    //        Queue c = new Queue(ar);
    //
    //        ArrayList d = new ArrayList() { 1, 2, 3 };
    //        Hashtable h = new Hashtable()
    //        {
    //            {10, "토끼1" }, 
    //            {20, "토끼2" },
    //            {30, "토끼3" }
    //        };
    //        Console.WriteLine(h.Count);
    //        //스택, 큐 초기화 불가
    //        //Stack e = new Stack(ar) { 1, 2, 3 };
    //        //Queue f = new Queue(ar) { 1, 2, 3 };
    //
    //
    //    }
    //    // var타입은 함수 파라메타로 사용할 수 없다.
    //    // public static void Add(var a)
    //    public static void Add(object a)
    //    {
    //    }
    //}
    //------------------------------------
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        ArrayList a = new ArrayList();
    //        a.Add(10); a.Add(20); a.Add(30);
    //
    //        Console.WriteLine(a[0] + " " + a[1] + " " + a[2]);
    //        a[1] = 99;
    //        Console.WriteLine(a[0] + " " + a[1] + " " + a[2]);
    //        //---차이(아래코드가 가능하게 하기 위해서는 따로 클래스 처리가 필요하다.)
    //        MyList ml = new MyList();
    //        ml[0] = 10;
    //        ml[1] = 20;
    //        ml[2] = 30;
    //    }
    //    class MyList
    //    {
    //        public int this[int index]
    //        {
    //            get { return ar[index]; }
    //            set { 
    //                if(index >= ar.Length)
    //                {
    //                    Array.Resize<int>(ref ar, index + 1);
    //                }
    //                ar[index] = value; 
    //            }
    //        }
    //        private int[] ar;
    //
    //        public MyList()
    //        {
    //            ar = new int[3];
    //        }
    //    }
    //}
    //----------------IEnumerator(foreach문 정의하기)
    //class Program
    //{
    //    class A
    //    {
    //        int[] ar = { 10, 20, 30, 40, 50 };
    //        public IEnumerator GetEnumerator()
    //        {
    //            // yield return은 함수 종료를 보류한다.
    //            for(int i = 0; i < ar.Length; i++)
    //            {
    //                yield return ar[i];
    //            }
    //            // 함수 중간에 종료하기 위해서는 yield break 사용
    //            yield break;
    //            Console.WriteLine(3);
    //            yield return ar[3];
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        A a = new A();
    //        // foreach는 GetEnumerator 함수를 호출한다.
    //        foreach (var item in a)
    //        {
    //            Console.WriteLine(item);
    //        }
    //    }
    //}
    //
    //-------------------------------------------------------------------------
    //-------------------------출발코드
    /*class Program
    {
        // 1. 표준 인터페이스 상속을 받는다.
        class A : IEnumerable, IEnumerator
        {
            int[] ar = { 10, 20, 30, 40, 50 };
            
        }
        static void Main(string[] args)
        {
            // yield return를 사용하지 않고 foreach를 사용하기 위해서는 IEnumerable, IEnumerator를 사용한다.
            A a = new A();
            foreach (var item in a)
            {
                Console.WriteLine(item);
            }
        }
    }*/
    //----------------------중간코드
    // 1. 표준 인터페이스 상속을 받는다.
    // 2. 단축키를 이용하여 인터페이스를 구현한다.
    // 3. 적당하게 코드를 수정한다.
    /*class Program
    {
     
        class A : IEnumerable, IEnumerator
        {
            int[] ar = { 10, 20, 30, 40, 50 };

            public object Current
            {
                get { return 100; }
            }
               

            public IEnumerator GetEnumerator()
            {
                Console.WriteLine("GetEnumerator");
                return null;
            }

            public bool MoveNext()
            {
                throw new NotImplementedException();
            }

            public void Reset()
            {
                throw new NotImplementedException();
            }
        }
        static void Main(string[] args)
        {
            // yield return를 사용하지 않고 foreach를 사용하기 위해서는 IEnumerable, IEnumerator를 사용한다.
            A a = new A();
            foreach (var item in a)
            {
                Console.WriteLine(item);
            }
        }*/
    //--------------------------------------------
    //class Program
    //{
    //    class A : IEnumerable, IEnumerator
    //    {
    //        int[] ar = { 10, 20, 30, 40, 50 };
    //
    //        public object Current
    //        {
    //            //끝나면 다시 MoveNext로 이동한다.
    //            get {
    //                Console.WriteLine("Current");
    //                // ar[pos]값이 foreach의 item으로 리턴듼다.
    //                return ar[pos]; 
    //            }
    //        }
    //
    //        public IEnumerator GetEnumerator()
    //        {
    //            Console.WriteLine("GetEnumerator");
    //            //this를 리턴하면 무조껀 MoveNext를 call하게 된다.
    //            return this;
    //        }
    //        int pos = -1;
    //        public bool MoveNext()
    //        {
    //            //pos == 4 면 반복 종료
    //            if(pos == ar.Length -1)
    //            {
    //                Console.WriteLine("End Looping");
    //                Reset();
    //                return false;
    //            }
    //            Console.WriteLine("MoveNext");
    //            pos++;
    //            // 반복이 끝났을 경우 false를 리턴한다.
    //            // true일 경우 반복이 끝나지 않았음을 표시(true일 때 current를 call한다.
    //            return true;
    //        }
    //        public void Reset()
    //        {
    //            pos = -1;
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        // yield return를 사용하지 않고 foreach를 사용하기 위해서는 IEnumerable, IEnumerator를 사용한다.
    //        A a = new A();
    //        foreach (var item in a)
    //        {
    //            Console.WriteLine(item);
    //        }
    //    }
    //}
    //-------------교재 예제 
    //class MyList : IEnumerable, IEnumerator
    //{
    //    private int[] array;
    //    int position = -1;
    //
    //    public MyList()
    //    {
    //        array = new int[3] { 1,2,3};
    //    }
    //
    //    public int this[int index]
    //    {
    //        get
    //        {
    //            return array[index];
    //        }
    //        set
    //        {
    //            if (index >= array.Length)
    //            {
    //                Array.Resize<int>(ref array, index + 1);
    //                Console.WriteLine($"Array Resized : {array.Length}");
    //            }
    //
    //            array[index] = value;
    //        }
    //    }
    //
    //    public object Current
    //    {
    //        get
    //        {
    //            return array[position];
    //        }
    //    }
    //
    //    public bool MoveNext()
    //    {
    //        if (position == array.Length - 1)
    //        {
    //            Reset();
    //            return false;
    //        }
    //
    //        position++;
    //        return (position < array.Length);
    //    }
    //    public void Reset()
    //    {
    //        position = -1;
    //    }
    //    public IEnumerator GetEnumerator()
    //    {
    //        return this;
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        MyList list = new MyList();
    //        for (int i = 0; i < 5; i++)
    //        {
    //            list[i] = i;
    //        }
    //
    //        foreach (int e in list)
    //        {
    //            Console.WriteLine(e);
    //        }
    //    }
    //}
    #endregion
    #region 11장 일반화 프로그래밍
    //class Program
    //{
    //    static void f1(int a)
    //    {
    //        int b;
    //        b = a;
    //        Console.WriteLine(a + " " + b);
    //    }
    //    static void f1(string a)
    //    {
    //        string b;
    //        b = a;
    //        Console.WriteLine(a + " " + b);
    //    }
    //
    //    class Tiger{}
    //    static void f1(Tiger a)
    //    {
    //        Tiger b;
    //        b = a;
    //        Console.WriteLine(a + " " + b);
    //    }
    //    // 제네릭을 사용하는 방법
    //    // f2<T> == f2<형식매개변수>
    //    static void f2<T>(T a)
    //    {
    //        T b;
    //        b = a;
    //        Console.WriteLine(a + " " + b);
    //        //T[] ar = new T[10];
    //    }
    //    static void Main(string[] args)
    //    {
    //        f1(10);
    //        f1("호랑이");
    //        f1(new Tiger());
    //        // 컴파일 시 위와 아래는 동일하게 생성됨(메모리 측면에서 동일하게 사용된다.)
    //        f2<int>(10);
    //        f2<string>("호랑이");
    //        f2<Tiger>(new Tiger());
    //    }
    //}
    //----------------------------------------------------------------
    //class Program
    //{
    //    // dest(target) >> destination(받는놈), src(original) = source(주는놈)
    //    // 함수 혹은 클래스는 형식매개변수를 선언한다.
    //    static void copy<T>(T[] dest, T[] src)
    //    {
    //        for (int i = 0; i < src.Length; i++)
    //        {
    //            dest[i] = src[i];
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        int[] ar = { 10, 20, 30 };
    //        int[] br = new int[ar.Length];
    //        // 함수 호출시에 타입을 명시하여 호출 혹은 생성한다.
    //        copy<int>(br, ar);
    //        foreach (var item in br)
    //        {
    //            Console.WriteLine(item + " ");
    //        }Console.WriteLine();
    //
    //        string[] cr = { "호랑이", "코끼리", "독수리" };
    //        string[] dr = new string[cr.Length];
    //        copy<string>(dr, cr);
    //        foreach (var item in dr)
    //        {
    //            Console.WriteLine(item + " ");
    //        }
    //        Console.WriteLine();
    //    }
    //}
    //class Program
    //{
    //    static void Swap<T>(ref T lhs ,ref T rhs)
    //    {
    //        T temp = lhs;
    //        lhs = rhs;
    //        rhs = temp;
    //    }
    //    static void Main(string[] args)
    //    {
    //        int a = 10, b = 20;
    //        Swap<int>(ref a, ref b);
    //        // 20 10
    //        Console.WriteLine(a + " " + b);
    //        
    //        float c = 10.1f, d = 20.1f;
    //        Swap<float>(ref c, ref d);
    //        // 20 10
    //        Console.WriteLine(c + " " + d);
    //    } 
    //}
    //class Program
    //{
    //   
    //   
    //    class MyList<T>
    //    {
    //        private T[] array;
    //        public MyList()
    //        {
    //            array = new T[3];
    //        }
    //        public T this[int index]
    //        {
    //            get 
    //            {
    //                //Console.WriteLine("get 사용");
    //                return array[index]; 
    //            }
    //            set
    //            {
    //                //Console.WriteLine("set 사용");
    //                array[index] = value;
    //            }
    //        }
    //        public int Length
    //        {
    //            get { return array.Length; }
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        MyList<int> nLi = new MyList<int>();
    //        Console.WriteLine(1);
    //        nLi[0] = 10;
    //        Console.WriteLine(2);
    //        nLi[1] = 20;
    //        Console.WriteLine(3);
    //        nLi[2] = 30;
    //        Console.WriteLine(nLi[0]);
    //
    //        MyList<string> strLi = new MyList<string>();
    //        strLi[0] = "호랑이";
    //        strLi[1] = "코끼리";
    //        strLi[2] = "독수리";
    //        for (int i = 0; i < strLi.Length; i++)
    //        {
    //            Console.WriteLine(strLi[i]);
    //        }
    //    }
    //}
    //------------------------------------------------------
    //class Program
    //{
    //    class A { }
    //    //ex1)
    //    class B<T>
    //    {
    //        public void f1(T a, T b){}
    //    }
    //    //형식 매개 변수를 제약 시킬 수 있다.
    //    //ex2) (int)T를 값으로만 치환시킬 수 있도록한다.
    //    class C<T> where T : struct 
    //    {
    //        public void f1(T a, T b) { }
    //    }
    //    //ex3) T를 클래스,객체 형식으로만 치환시킬 수 있도록한다.
    //    class D<T> where T : class 
    //    {
    //        public void f1(T a, T b) { }
    //    }
    //    //ex4) 반드시 디폴트 생성자가 있는 개체를 생성해야한다.
    //    class E<T> where T : new()
    //    {
    //
    //    }
    //    //ex5) Fruit를 부모로 하는 자식 객체만 받아라
    //    // 반드시 기반(베이스)클래스의 파생클래스 이어야 한다.
    //    class Fruit { }
    //    class Apple:Fruit { }
    //    class Banana { }
    //    class F<T> where T : Fruit
    //    { 
    //        
    //    }
    //    // ex6)반드시 ITest 인터페이스를 구현한 객체만 받으세요.
    //    interface ITest
    //    {
    //        public void f1();
    //    }
    //    class G1 { } // 상속 안받음
    //    class G2 : ITest
    //    {// 상속 받음
    //        public void f1() { }
    //    }
    //    class H<T> where T: ITest
    //    {
    //
    //    }
    //
    //    //ex7)
    //    class Animal { }
    //    class Ttiger : Animal { }
    //    class Lion { }
    //
    //    class J<U> where U : Animal
    //    {
    //        //T의 타입으로 사용 가능한 것은 U타입으로 정의된 것만 사용할 수 있다.
    //        public void f1<T>(T a) where T : U { }
    //    }
    //
    //    static void Main(string[] args)
    //    {
    //        //ex1)
    //        B<int> b1 = new B<int>();
    //        B<string> b2 = new B<string>();
    //        B<A> b3 = new B<A>();
    //
    //        //ex2)
    //        C<int> c1 = new C<int>();
    //        //C<string> c2 = new C<string>();
    //        //C<A> c3 = new C<A>();
    //        
    //        //ex3)
    //        //D<int> c1 = new D<int>();
    //        D<string> c2 = new D<string>();
    //        D<A> c3 = new D<A>();
    //
    //        E<A> e = new E<A>();
    //        //ex5)
    //        F<Apple> f1 = new F<Apple>();
    //
    //        //F<Banana> f1 = new F<Banana>();
    //        //ex6)
    //        // H<G1> h1 = = new H<G1>(); // 사용 불가
    //
    //        //ex7)
    //        J<Tiger> j = new J<Tiger>();
    //        j.f1(new Tiger());
    //    }
    //}
    #endregion
    #region 12장 예외처리
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        try
    //        {
    //            int? a = null;
    //            int b = a ?? throw new Exception("널 입니다");
    //        }
    //        catch (Exception e)
    //        {
    //            Console.WriteLine(e.Message);
    //        }
    //
    //        try
    //        {
    //            int[] ar = { 0, 1, 2 };
    //            int index = 4;
    //            int value = ar[index >= 0 && index <= 2 ? index : throw new Exception("인덱션 오류")];
    //        }
    //        catch (Exception e)
    //        {
    //            Console.WriteLine(e.Message);
    //        }
    //        finally
    //        {
    //            Console.WriteLine("finally");
    //        }
    //    }
    //
    //}
    //----------------------------------------
    //class Program
    //{
    //    class MyMyException : Exception
    //    {
    //        public MyMyException() { }
    //        public MyMyException(string message) : base(message)
    //        { 
    //        }
    //        public object AAA{get; set;}
    //        public object BBB{get; set;}
    //    }
    //
    //    static uint f1(uint a, uint r, uint g, uint b)
    //    {
    //        // 반복처리
    //        uint[] args = new uint[] { a, r, g, b };
    //        foreach (var item in args)
    //        {
    //            if (item > 0xff)
    //            {
    //                throw new MyMyException()
    //                {
    //                    AAA = item,
    //                    BBB = "0부터 255"
    //                };
    //            }
    //        }
    //        uint result = (a << 24) + (r << 16) + (g << 8) + b;
    //        return result;
    //    }
    //    static void Main(string[] args)
    //    {
    //        try
    //        {
    //            Console.WriteLine(1);
    //            Console.WriteLine("{0:X}", f1(0x10, 0x20, 0xaf, 0x40));
    //            Console.WriteLine(2);
    //            Console.WriteLine("{0:X}", f1(0x1ff, 0x20, 0xaf, 0x40));
    //            Console.WriteLine(3);
    //        }
    //        catch(MyMyException e)
    //        {
    //            Console.WriteLine(e.Message);
    //            Console.WriteLine(e.AAA + " " + e.BBB);
    //        }
    //        Console.WriteLine(4);
    //    }
    //}
    //------------------------------------------------------------
    //class Program
    //{
    //    class MyMyException : Exception
    //    {
    //        public int Number { get; set; }
    //    }
    //    static void Main(string[] args)
    //    {
    //        try
    //        {
    //            // 0~10 사이값이면 정상 처리하고
    //            // 음수이면 음수 예외처리하고
    //            // 10이상이면 이것도 예외처리하자
    //            int num = 25;
    //            if (num < 0 || num > 10)
    //            {
    //                throw new MyMyException()
    //                {
    //                    Number = num
    //                };
    //            }
    //            else
    //            {
    //                Console.WriteLine("정상");
    //            }
    //        }
    //        catch (MyMyException e) when ( e.Number < 0 )
    //        {
    //            Console.WriteLine("음수 익셉션");
    //        }
    //        catch (MyMyException e) when ( e.Number > 10 )
    //        {
    //            Console.WriteLine("범위 초과 익셉션");
    //        }
    //        
    //    }
    //}
    #endregion
    #region 13장 델리게이트
    // 대리자 : delegate >> 포인터 함수
    // 1. 동일한 함수 원형을 정의하고 앞에 델리게이트를 붙이고 이름정의
    // 2. delegate 객체 생성( MyDelegate를 클래스라고 생각하자.)
    // 3. 객체 생성시 생성자 인수(함수)를 전달한다.
    //delegate void 정렬(int a, string b);
    //class Program
    //{
    //    // 정렬
    //    //      순차정렬
    //    //      역순정렬
    //    // 요리
    //    //      한식요리
    //    //      일식요리
    //    //      중식요리
    //    static void 한식요리(int a, string b)  { Console.WriteLine(1); }
    //    static void 일식요리(int a, string b)  { Console.WriteLine(2); }
    //    static void 중식요리(int a, string b)  { Console.WriteLine(3); }
    //
    //    static void Main(string[] args)
    //    {
    //        // 방법1
    //        F3 ttt = new F3(f1);
    //        ttt(2, "tiger");
    //        ttt = new F3(f2);
    //        ttt(2, "tiger");
    //    }
    //}
    //---------------------------------------------------------
    //class A
    //{
    //    public int PlusCal(int a, int b)
    //    { return a + b; }
    //    public int MinusCal(int a, int b)
    //    { return a - b; }
    //}
    //delegate int Cal(int a, int b);
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Cal cal = new Cal(new A().PlusCal);
    //        Console.WriteLine(cal(3, 4));
    //        
    //        cal = new Cal(new A().MinusCal);
    //        Console.WriteLine(cal(3, 4));
    //
    //    }
    //}
    //--------------------------------------------
    //for (int i = 0; i < 5; i++)
    //{
    //    for (int j = 0; j < 5 - i; j++)
    //    {
    //        Write( "[{0} {1}]", j, j+1 );
    //}
    //WriteLine();
    //}
    // 검색, 삽입, 삭제 <-- 리스트
    // 선입선출, 선입후출 <== 스택, 큐
    // 적절한 것 사용
    //class Program
    //{
    //    class MyTuple
    //    {
    //        public int Num1 { set; get; }
    //        public int Num2 { set; get; }
    //    }
    //    static void Main(string[] args)
    //    {
    //        MyTuple[] tp = new MyTuple[5];
    //        Stack<MyTuple> stack = new Stack<MyTuple>();
    //        for (int i = 0; i < tp.Length; i++)
    //        {
    //            tp[i] = new MyTuple();
    //            tp[i].Num1 = i;
    //            tp[i].Num2 = i + 1;
    //            stack.Push(tp[i]);
    //        }
    //
    //        while (stack.Count != 0)
    //        {
    //            for (int i = 0; i < stack.Count; i++)
    //            {
    //                Console.Write($"[{tp[i].Num1} {tp[i].Num2}]");
    //            }
    //            Console.WriteLine();
    //            stack.Pop();
    //        }
    //    }
    //}
    //------------------------------------------------
    //class Program
    //{
    //    delegate int Compare(int a, int b);
    //    static int AscendCompare(int a, int b)
    //    {
    //        if (a > b)
    //            return 1;
    //        else if (a == b)
    //            return 0;
    //        else
    //            return -1;
    //    }
    //    static int DescendCompare(int a, int b)
    //    {
    //        if (a < b)
    //            return 1;
    //        else if (a == b)
    //            return 0;
    //        else
    //            return -1;
    //    }
    //    static void BubbleSort(int[] DataSet, Compare compare)
    //    {
    //        for (int i = 0; i < DataSet.Length - 1; i++)
    //        {
    //            for (int j = 0; j < DataSet.Length - 1 - i; j++)
    //            {
    //                if (compare(DataSet[j], DataSet[j + 1]) > 0)
    //                {
    //                    int t = DataSet[j + 1];
    //                    DataSet[j + 1] = DataSet[j];
    //                    DataSet[j] = t;
    //                }
    //            }
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        int[] array = { 3, 7, 4, 2, 10 };
    //        // 순차 정렬
    //        Compare compare = new Compare(AscendCompare);
    //        BubbleSort(array, compare);
    //        foreach (var item in array)
    //        {
    //            Console.WriteLine(item + " ");
    //        }
    //        Console.WriteLine();
    //
    //        compare = new Compare(DescendCompare);
    //        BubbleSort(array, compare);
    //        foreach (var item in array)
    //        {
    //            Console.WriteLine(item + " ");
    //        }
    //        Console.WriteLine();
    //    }
    //}
    //----------------제네릭 델리게이트
    //class Program
    //{
    //    delegate int Compare<T>(T a, T b);
    //    static int AscendCompare<T>(T a, T b) where T : IComparable<T>
    //    {
    //        // T 타입은 산술, 관계(비교), 논리 연산 불가
    //        // a, b가 객체가 넘어 오면 비교 대상이 안되기 때문
    //        // 문자열이 넘어오면 비교 대상에 맞지 않음
    //        //if (a > b)
    //        //    return 1;
    //        //else if (a == b)
    //        //    return 0;
    //        //else
    //        //    return -1;
    //
    //        // 해결책
    //        //int는 IComparable를 상속 받아서 넘어온다.
    //
    //
    //        int x = 10, y = 20;
    //        int r = x.CompareTo(y);
    //        return a.CompareTo(b);
    //        
    //    }
    //    static int DescendCompare<T>(T a, T b) where T : IComparable<T>
    //    {
    //        return b.CompareTo(a);
    //    }
    //    
    //    static void BubbleSort<T>(T[] DataSet, Compare<T> compare)
    //    {
    //        for (int i = 0; i < DataSet.Length - 1; i++)
    //        {
    //            for (int j = 0; j < DataSet.Length - 1 - i; j++)
    //            {
    //                if (compare(DataSet[j], DataSet[j + 1]) > 0)
    //                {
    //                    T t = DataSet[j + 1];
    //                    DataSet[j + 1] = DataSet[j];
    //                    DataSet[j] = t;
    //                }
    //            }
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        const int num = 10;
    //        int[] array = new int[num]; // 0 - 100
    //        for (int i = 0; i < 10; i++)
    //        {
    //            Random random = new Random();
    //            array[i] = random.Next(100);
    //            Console.WriteLine(array[i] + " ");
    //        }
    //
    //        Compare<int> compare = new Compare<int>(AscendCompare);
    //        // 순차 정렬
    //        BubbleSort<int>(array, compare);
    //        foreach (var item in array)
    //            Console.Write(item + " ");
    //        Console.WriteLine();
    //
    //        compare = new Compare<int>(DescendCompare);
    //        // 역순 정렬
    //        BubbleSort<int>(array, compare);
    //        foreach (var item in array)
    //            Console.Write(item + " ");
    //        Console.WriteLine();
    //    }
    //}
    //class Program
    //{
    //    // 대소문자 통일성, 변수명
    //    delegate void ThereIsFire(string loc);
    //    static void Call119(string loc)
    //    {
    //        Console.WriteLine("불이남. 여기 주소는 {0}", loc);
    //    }
    //    static void ShoutOut(string loc)
    //    {
    //        Console.WriteLine("피하자. {0}에서 불이남", loc);
    //    }
    //    static void Escape(string loc)
    //    {
    //        Console.WriteLine("{0}에서 탈출하자", loc);
    //    }
    //    static void Main(string[] args)
    //    {
    //        ThereIsFire fire1 = new ThereIsFire(Call119);
    //        fire1 += new ThereIsFire(ShoutOut);
    //        fire1 += new ThereIsFire(Escape);
    //        fire1("강남구");
    //
    //        Console.WriteLine();
    //        ThereIsFire fire2 = 
    //            new ThereIsFire(Call119)
    //            + new ThereIsFire(ShoutOut)
    //            + new ThereIsFire(Escape);
    //        fire1("역삼동");
    //    }
    //}
    //-------------------------------------------
    //class Program
    //{
    //    delegate void Notify(string msg);
    //    class Notifier
    //    {
    //        public Notify EventOccured;
    //    }
    //
    //    class EventListner
    //    {
    //        private string name;
    //        public EventListner(string name){this.name = name;}
    //
    //        public void output(string msg)
    //        {
    //            Console.WriteLine(name + " " + msg);
    //        }
    //    }
    //
    //    static void Main(string[] args)
    //    {
    //        Notifier notifier = new Notifier();
    //        EventListner ev1 = new EventListner("호랑이");
    //        EventListner ev2 = new EventListner("코끼리");
    //        EventListner ev3 = new EventListner("독수리");
    //
    //        notifier.EventOccured += ev1.output;
    //        notifier.EventOccured += ev2.output;
    //        notifier.EventOccured += ev3.output;
    //        notifier.EventOccured("메세지");
    //        Console.WriteLine();
    //
    //        //notifier.EventOccured -= ev2.output;
    //        //notifier.EventOccured("메세지2");
    //        //Console.WriteLine();
    //        //
    //        //notifier.EventOccured = new Notify(ev2.output)
    //        //    + new Notify(ev3.output);
    //        //
    //        //notifier.EventOccured("핵이 떨어짐");
    //        //Console.WriteLine();
    //        //
    //        //Notify notify1 = new Notify(ev1.output);
    //        //Notify notify2 = new Notify(ev2.output);
    //        //notifier.EventOccured = (Notify)Delegate.Combine(notify1, notify2);
    //        //notifier.EventOccured("Fire !!");
    //        //
    //    }
    //}
    //---------------------------------------------------------
    //delegate int Calculate(int a, int b);
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        // 1번 방법
    //        //Calculate calculate = new Calculate(비븟한 함수)''
    //
    //        // 2번 방법
    //        //Calculate calculate;
    //        //calculate = new Calculate;//(비슷한 함수);
    //        //calculate(1, 2);
    //
    //        // 3번 방법 (익명함수 혹은 델리게이트 함수)
    //        // new가 날아가고, 생성자에 함수 넢는 부분이 날아갔다.
    //        Calculate calculate = delegate (int a, int b)
    //        {
    //            Console.WriteLine("나는 익명 함수");
    //            return a + b;
    //        };
    //        calculate(1, 2);
    //        //-------------------
    //        // 방법1
    //        //f1( new Calculate(비슷한 함수) );
    //
    //        // 방법2
    //        // 함수를 미리 만들어 놓지 않고
    //        // 필요할 때 동적으로 함수를 생성 시켜서 실행시키고 싶을때(사용하고 제거해버림)
    //        f1(delegate (int a, int b)
    //        {
    //            Console.WriteLine("나는 익명 함수");
    //            return a + b;
    //        });
    //        f1(delegate (int a, int b)
    //        {
    //            Console.WriteLine("너는 익명 함수");
    //            return a + b;
    //        });
    //    }
    //    static void f1(Calculate calculate)
    //    {
    //        calculate(1, 2);
    //    }
    //}
    //----------------------------------------------
    //delegate void EventHandle(string message);
    //
    //class MyNotifier
    //{
    //    // event를 사용하는 이유는 클래스 외부에서 호출할 수 없도록 하는 것이다.
    //    // private으로 만들면 되지 않는가?
    //    public event EventHandle SomthingHappened;// = new EventHandle(비슷한 함수);
    //    public void Dosomthing()
    //    {
    //        SomthingHappened( "버튼 클릭 이벤트 발생" );
    //    }
    //}
    //
    //class Program
    //{
    //    static void MyHandler(string message)
    //    {
    //        Console.WriteLine(message);
    //    }
    //    static void Main(string[] args)
    //    {
    //        MyNotifier myNotifier = new MyNotifier();
    //        // = new로 사용할 수 없고 += new
    //        myNotifier.SomthingHappened += new EventHandle(MyHandler);
    //        // 1. SomethingHappened를 [클래스 외부에서] 호출할 수 없다.
    //        //myNotifier.SomthingHappened("호랑이");
    //        myNotifier.Dosomthing();
    //    }
    //}
    #endregion
    #region 14장 람다식
    //delegate int Cal(int a, int b);
    //delegate void DoSomthing();
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        Cal cal1 = delegate (int a, int b)
    //        {
    //            return a + b;
    //        };
    //
    //        Cal cal2 = (a, b) =>{return a + b;};
    //
    //        Console.WriteLine(cal2(3,4));
    //
    //        // 실행문이 단문장일 때 {}를 생략할 수 있는데 이때 return도 같이 생략해야한다.
    //        Cal cal3 = (a, b) => a + b;
    //        Console.WriteLine(cal3(3,4));
    //
    //        DoSomthing do1 = () =>
    //        {
    //            Console.WriteLine();
    //        };
    //        do1();
    //    }
    //}
    //---------------------------------------------
    //class Program
    //{
    //    delegate string Concat(string[] args);
    //
    //    static void Main(string[] args)
    //    {
    //        Concat concat = (xxx) => 
    //        {
    //            string r = " ";
    //            foreach(var item in xxx)
    //            {
    //                r += item + " ";
    //            }
    //            return r;
    //        };
    //        string[] ar = { "호랑이", "코끼리", "독수리" };
    //        Console.WriteLine( concat(ar) );
    //    }
    //}
    //-----------------------------------------
    //class Program
    //{
    //    delegate int Test01();
    //    delegate int Test02(int a);
    //    delegate int Test03(int a, int b);
    //
    //    static void Main(string[] args)
    //    {
    //        Test01 t1 = () =>
    //        {
    //            return 10;
    //        };
    //        Test02 t2 = (a) =>
    //        {
    //            return a;
    //        };
    //        Test03 t3 = (a, b) =>
    //        {
    //            return a + b;
    //        };
    //
    //        // 리턴이 int 임을 알린다.
    //        // Func delegate
    //        Func<int> f1 = () =>
    //        {
    //            return 20;
    //        };
    //        Console.WriteLine( f1());
    //
    //        Func<string> f2 = () =>
    //        {
    //            return "tiger";
    //        };
    //        Console.WriteLine(f2());
    //
    //        Func<string> f3 = () =>
    //        {
    //            Console.WriteLine("호랑이");
    //            return "tiger";
    //        };
    //
    //        Func<string> f4 = () => "tiger";
    //
    //        Func<int, string> f5 = (a) =>
    //        {
    //            Console.WriteLine(a);
    //            return "tiger";
    //        };
    //        Console.WriteLine(f5(10));
    //
    //        Func<string, string, int> f6 = (a, b) =>
    //        {
    //            Console.WriteLine(a + b);
    //            return 100;
    //        };
    //        Console.WriteLine(f6("호랑이", "독수리"));
    //
    //        Func<string, string, int> f7 = (a, b) => 100;
    //        Console.WriteLine(f7("호랑이", "독수리"));
    //        // 인수 전달은 총 16개까지 가능
    //
    //        // 리턴이 없는 델리게이트는 Action 델리게이트
    //        // 에러 이유. (return가 생략된것이기 때문에 에레
    //        //Action<> f8 = () => 100;
    //        Action f8 = () => {Console.WriteLine("호랑이");};
    //        Action<int, int, string> f9 = (a, b, c) =>
    //        {
    //            Console.WriteLine(a + b + c);
    //        };
    //        f9(10, 20, " test");
    //    }
    //}
    //---------------------------------------------------
    //class Program
    //{
    //    //// 1. using System.Linq 
    //    //// 2. 결과값은 var 타입으로 받는다.
    //    //// 3. 기본형은 from select
    //    //static void Main(string[] args)
    //    //{
    //    //    int[] ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //    //
    //    //    var result = from n in ar   // n은 변수가 아니다. 명령어 형식이다.
    //    //                 select n;
    //    //    foreach (var item in result)
    //    //        Console.Write( item + " ");
    //    //    Console.WriteLine();
    //    //
    //    //    result = from n in ar   // n은 변수가 아니다. 명령어 형식이다.
    //    //                 where n % 2 == 0
    //    //                 select n;
    //    //
    //    //    foreach (var item in result)
    //    //        Console.Write(item + " ");
    //    //    Console.WriteLine();
    //    //
    //    //    result = from n in ar   // n은 변수가 아니다. 명령어 형식이다.
    //    //             where n % 2 == 0
    //    //             orderby n descending
    //    //             select n;
    //    //
    //    //    foreach (var item in result)
    //    //        Console.Write(item + " ");
    //    //}
    //    //------------------------------------------
    //    //class Info
    //    //{
    //    //    public string Name { get; set; } // 약식
    //    //    public int Height { get; set; }
    //    //}
    //    //static void Main(string[] args)
    //    //{
    //    //    Info[] infos = new Info[5]
    //    //    {
    //    //        new Info(){ Name = "호랑이1", Height = 186},
    //    //        new Info(){ Name = "호랑이2", Height = 158},
    //    //        new Info(){ Name = "호랑이3", Height = 172},
    //    //        new Info(){ Name = "호랑이4", Height = 178},
    //    //        new Info(){ Name = "호랑이5", Height = 171}
    //    //    };
    //    //    //info[0] = new Info();
    //    //    //info[0].Name = "호랑이";
    //    //    //info[0].Height = 100;
    //    //
    //    //    var result1 = from obj in infos
    //    //                 where obj.Height < 175
    //    //                 // orderby obj.Height descending
    //    //                 select obj;
    //    //    foreach (var item in result1)
    //    //    {
    //    //        Console.WriteLine(item.Name + " " + item.Height);
    //    //    }Console.WriteLine();
    //    //
    //    //    // 데이터 추가하는 것과 관련됨
    //    //    var result2 = from obj in infos
    //    //                  where obj.Height < 175
    //    //                  // orderby obj.Height descending
    //    //                  select new
    //    //                  {
    //    //                      n = obj.Name,
    //    //                      h = obj.Height
    //    //                  };
    //    //    foreach (var item in result2)
    //    //    {
    //    //        Console.WriteLine(item.n + " " + item.h);
    //    //        //Console.WriteLine(item.Name + " " + item.Height);
    //    //    }
    //    //    Console.WriteLine();
    //    //}
    //    //----------------------------------------------------
    //    //class Class
    //    //{
    //    //    public string Name { get; set; } // 약식
    //    //    public int[] Score { get; set; }
    //    //}
    //    //static void Main(string[] args)
    //    //{
    //    //    Class[] arrClass =
    //    //    {
    //    //        new Class(){ Name = "호랑이1", Score = new int[]{99, 80, 70, 24} },
    //    //        new Class(){ Name = "호랑이2", Score = new int[]{60, 45, 87, 72} },
    //    //        new Class(){ Name = "호랑이3", Score = new int[]{92, 30, 85, 94} },
    //    //        new Class(){ Name = "호랑이4", Score = new int[]{90, 88, 0, 17} }
    //    //    };
    //    //
    //    //    var result = from c in arrClass
    //    //                 from s in c.Score
    //    //                 where s < 60
    //    //                 select new
    //    //                 {
    //    //                     Name = c.Name,
    //    //                     Lowest = s
    //    //                 };
    //    //    foreach (var item in result)
    //    //    {
    //    //        Console.WriteLine(item.Name + " " + item.Lowest);
    //    //    }
    //    //} 
    //}
    #endregion
    #region 16장
    //class Program
    //{
    //    // dynamic은 어떤 경우에 사용하는가?
    //    // 1. 덕타이핑 할 때 dynamic을 사용한다.
    //    // 2. COM 컴포넌트 프로그램을 작성할 때
    //    // 3. 언어의 호환.
    //    class Test 
    //    {
    //        public void f1() { }
    //    }
    //    static void Main(string[] args)
    //    {
    //        //컴파일할때 타입이 확정 되는 것이 아니고
    //        //프로그램 실행될 때 타입이 확정된다.(런타임)
    //        Test t1 = new Test();
    //        t1.f1();
    //        t1.f2();
    //        // t1,f2();
    //        // 꼭 필요하면 사용해야 되지만, 조심해야 한다.
    //        dynamic t2 = new Test();
    //        t2.f1();
    //        t2.f2(); // 에러가 뜨지 않는다.(실행시 에러가 뜬다.)
    //
    //        // 오리 타이핑(덕 타이핑)
    //        dynamic[] ar = { new Duck(), new Apple(), new Mallard() };
    //        ar[0].quack();
    //        ar[1].quack();
    //        ar[2].quack();
    //    }
    //    // 오리 클래스이다.
    //    class Duck
    //    {
    //        public void quack() { }
    //    }
    //    class Apple
    //    {
    //        public void quack() { }
    //    }
    //    class Mallard
    //    {
    //        public void quack() { }
    //    }
    //
    //}
    #endregion
    #region 18장 파일 입출력
    // 직렬화임을 알린다.
    // 프리프로세스, 어노테이션
    //[Serializable]
    //class NameCard
    //{
    //    public string name;
    //    public string phone;
    //    public int age;
    //}
    //class Program
    //{
    //    //텍스트 파일만 전문적으로 입출력 하겠다.
    //    //StreamReader, StreamWriter
    //
    //    // 직렬화 (serialization)
    //    // 일반타입 말고, 구조체 혹은 클래스멤버 형식으로 파일 입출력 하는것.
    //    static void Main(string[] args)
    //    {
    //        Stream ws = new FileStream("d.txt", FileMode.Create);
    //        BinaryFormatter s = new BinaryFormatter();
    //
    //        NameCard nc = new NameCard();
    //        nc.name = "tiger";
    //        nc.phone = "010-1234-5678";
    //        nc.age = 100;
    //        s.Serialize(ws, nc);
    //
    //        ws.Close();
    //
    //        Stream rs = new FileStream("d.txt", FileMode.Open);
    //        BinaryFormatter d = new BinaryFormatter();
    //
    //        NameCard nc2;
    //        nc2 = (NameCard)d.Deserialize(rs);
    //        Console.WriteLine(nc2.name);
    //        Console.WriteLine(nc2.phone);
    //        Console.WriteLine(nc2.age);
    //        rs.Close();
    //    }
    //}
    //-----------리스트 + 직렬화
    //[Serializable]
    //class NameCard
    //{
    //    public string name;
    //    public string phone;
    //    public int age;
    //    public NameCard(string name, string phone, int age)
    //    {
    //        this.name = name;
    //        this.phone = phone;
    //        this.age = age;
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args) 
    //    {
    //        Stream ws = new FileStream("e.txt", FileMode.Create);
    //        BinaryFormatter s = new BinaryFormatter();
    //        List<NameCard> li = new List<NameCard>();
    //        li.Add(new NameCard("호랑이1", "12324", 10));
    //        li.Add(new NameCard("호랑이2", "12324", 20));
    //        li.Add(new NameCard("호랑이3", "12324", 30));
    //        s.Serialize(ws, li);
    //        ws.Close();
    //
    //        Stream rs = new FileStream("e.txt", FileMode.Open);
    //        BinaryFormatter d = new BinaryFormatter();
    //        List<NameCard> li2;
    //        li2 = (List<NameCard>)d.Deserialize(rs);
    //        rs.Close();
    //
    //        foreach (var item in li2)
    //        {
    //            Console.WriteLine(item.name + " " + 
    //                item.age + " " + item.phone);
    //        }
    //    }
    //}
    #endregion
    #region 19장 스레드
    //// 응용 프로그램이 2개 돌고 있다.(프로세스가 2개 돌고 있다.)
    //// 1개의 응용 프로그램 안에서 3개의 스레드가 돌고 있다.
    //class Program
    //{
    //    static void f1()
    //    {
    //        for (int i = 0; i < 7; i++)
    //        {
    //            Console.WriteLine("Thread1:" + i);
    //            Thread.Sleep(1000);
    //        }
    //    }
    //    static void Main(string[] args)
    //    {
    //        // Thread t1 = new Thread();
    //        Thread t1 = new Thread(new ThreadStart(f1));
    //        t1.Start();
    //        for(int i = 0; i < 5; i++)
    //        {
    //            Console.WriteLine("Main:"+ i);
    //            Thread.Sleep(1000);
    //        }
    //        // 블록킹
    //        t1.Join();
    //        Console.WriteLine("프로그램 종료");
    //    }
    //}
    //----------------------------------------------------
    //class MyClass
    //{
    //    // 1.다중 스레드에서 공통으로 사용하는 변수는
    //    // 무조건 크리티컬 섹션 처리 필수
    //    // 2. 크리티컬 섹션에서 시간을 최대한 빨리 처리하는 코드로 구성해야한다.
    //    // ->다른 스레드가 사용을 못하기 때문
    //    // 3. 최대한 스레드에서는 공용변수를 줄인다.
    //    public int count = 0;
    //    private readonly object cs = new object();
    //    public void Inc()
    //    {
    //        // 문제 해결을 위해서 나온 것이 크리티컬 섹션.
    //        for (int i = 0; i < 10000; i++)
    //        {
    //            // lock로 블록(스코프) 잡혀 있는 코드는 
    //            // 블록을 탈출하기 전까지는 다른 쓰레드가 진입불가
    //            //lock(cs)
    //            //{
    //            //    count += 1;
    //            //    count += 1;
    //            //}
    //            // 아래와 같이 변경해야 더 좋은 코드
    //            lock (cs)
    //            {
    //                count += 1;
    //            }
    //            lock (cs)
    //            {
    //                count += 1;
    //            }
    //        }
    //    }
    //}
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        MyClass obj = new MyClass();
    //        Thread t1 = new Thread(new ThreadStart(obj.Inc));
    //        Thread t2 = new Thread(new ThreadStart(obj.Inc));
    //        Thread t3 = new Thread(new ThreadStart(obj.Inc));
    //        Thread t4 = new Thread(new ThreadStart(obj.Inc));
    //        Thread t5 = new Thread(new ThreadStart(obj.Inc));
    //        t1.Start();
    //        t2.Start();
    //        t3.Start();
    //        t4.Start();
    //        t5.Start();
    //
    //        t1.Join();
    //        t2.Join();
    //        t3.Join();
    //        t4.Join();
    //        t5.Join();
    //
    //        Console.WriteLine(obj.count);
    //    }
    //}
    //---------------------------
    //class Program
    //{
    //    //public static void f1()
    //    //{
    //    //    Thread.Sleep(2000);
    //    //    Console.WriteLine(1);
    //    //}
    //    static void Main(string[] args)
    //    {
    //        // 병렬처리
    //        var task = Task.Run(() =>
    //        {
    //            Thread.Sleep(2000);
    //            Console.WriteLine("1");
    //        });
    //
    //        Console.WriteLine(2);
    //        task.Wait();
    //        Console.WriteLine(3);
    //
    //    }
    //}
    //------------------------------------
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        // cpu가 듀얼코어 이상에서 효과를 볼 수 있는 예제
    //        // Task<리턴 타입 설정>
    //        // List<int>가 리턴 된다.
    //        var task1 = Task<List<int>>.Run(() =>
    //        {
    //            Thread.Sleep(2000);
    //            List<int> list = new List<int>();
    //            list.Add(4);
    //            list.Add(5);
    //            list.Add(6);
    //            return list;
    //        });
    //        var task2 = Task<List<int>>.Run(() =>
    //        {
    //            Thread.Sleep(1000);
    //            List<int> list = new List<int>();
    //            list.Add(7);
    //            list.Add(8);
    //            list.Add(9);
    //            return list;
    //        });
    //        List<int> list = new List<int>();
    //        list.Add(1);
    //        list.Add(2);
    //        list.Add(3);
    //
    //        task1.Wait();
    //        task2.Wait();
    //        list.AddRange(task1.Result.ToArray());
    //        list.AddRange(task2.Result.ToArray());
    //        foreach (var item in list)
    //        {
    //            Console.WriteLine(item);
    //        }
    //    }
    //}
    //--------------------------------------------------
    // 소수 판단 프로그램이다.
    class Program
    {
        public static bool IsPrime(long num)
        {
            if (num < 2) { return false; }
            if (num % 2 == 0 && num != 2)
            {
                return false;
            }
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                { return false; }
            }
            return true;
        }
        static void Main(string[] args)
        {
            for (int ct = 1; ct <= 16; ct++)
            {
                long from = 0;
                long to = 20000;
                int taskCount = ct * 2;
                Func<object, List<long>> FindPrimeFunc = (objRange) =>
                {
                    long[] range = (long[])objRange;
                    List<long> found = new List<long>();
                    for (long i = range[0]; i < range[1]; i++)
                    {
                        if (IsPrime(i))
                            found.Add(i);
                    }
                    return found;
                };
    
                Task<List<long>>[] tasks = new Task<List<long>>[taskCount];
                long currentFrom = from;
                long currentTo = to / tasks.Length;
                for (int i = 0; i < tasks.Length; i++)
                {
                    tasks[i] = new Task<List<long>>(
                        FindPrimeFunc,
                        new long[] { currentFrom, currentTo }
                        );
                    //WriteLine("{0} {1}", currentFrom, currentTo);
                    currentFrom = currentTo + 1;
                    if (i == tasks.Length - 2)
                        currentTo = to;
                    else
                        currentTo = currentTo + (to / tasks.Length);
                }
                // Ready Go !!!!
                //ReadLine(); // 블로킹
                //WriteLine("Start !!!");
                DateTime startTime = DateTime.Now;
                //{
                //WriteLine(startTime);
                foreach (Task<List<long>> task in tasks)
                    task.Start();
                List<long> total = new List<long>();
                foreach (Task<List<long>> task in tasks)
                {
                    task.Wait();
                    total.AddRange(task.Result.ToArray());
                }
                //}
                DateTime endTime = DateTime.Now;
                TimeSpan ellaped = endTime - startTime;
                Console.WriteLine("{0} {1} {2}", ct, ellaped, total.Count);
                //WriteLine();
            }
        }
    }
    //----------------------------------------
    //class Program
    //{
    //    // 함수이름 앞에 async 있으면 코드 안에 await가 있다.
    //    async static void f1()
    //    {
    //        
    //        Console.WriteLine(2);
    //        var task = Task.Run(() =>
    //        {
    //            for (int i = 0; i < 3; i++)
    //            {
    //                Thread.Sleep(1000);
    //                Console.WriteLine( i * 10 + 10);
    //            }
    //        });
    //        Console.WriteLine(3);
    //        Thread.Sleep(500); // 테스트 용이다.
    //        Console.WriteLine("======================");
    //        // await를 만나면 호출한 측에 제어권을 main에 돌려준다.
    //        // 돌려줌과 동시에 블로킹 된다.( task.run 작업이 끝나면 블로킹이 풀린다.)
    //        await task; // 제어권이 돌아 간다.
    //        Console.WriteLine(4);
    //    }
    //    static void Main(string[] args)
    //    {
    //        Console.WriteLine(1);
    //        f1();
    //        Console.WriteLine(5);
    //        Console.ReadLine();
    //    }
    //}
    #endregion
}