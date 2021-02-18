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
    class A
    {
        public virtual void f1()
        {
            Console.WriteLine(1); 
        }
        
    }
    class B : A
    {
        public override void f1()
        {
            Console.WriteLine(2);
        }
    }
    class C : B
    {
        public override void f1()
        {
            Console.WriteLine(3);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            A a = new C();
            a.f1();
        }
    }
    #endregion
}
