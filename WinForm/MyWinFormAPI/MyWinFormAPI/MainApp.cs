using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Console;
using System.Drawing;

namespace MyWinFormAPI
{
    class MainApp : Form
    { 
        static void Main(string[] args)
        {
            Button button = new Button();
            button.Text = "클릭";
            button.Left = 100;
            button.Top = 50;
            // 함수 f1을 작성할 수도 있는데
            // 람다식으로 적용 한번 적용
            button.Click += (object s, EventArgs e) =>
            {
                MessageBox.Show("클릭 클릭");
            };
            MainApp form = new MainApp();
            form.Text = "폼 & 버튼컨트롤";
            form.Height = 150;

            // 버튼객체와 폼 객체의 연결 고리가 없다.
            // 자바의 스윙, 혹은 자바 FX
            form.Controls.Add(button);
            Application.Run(form);
        }

        static void f1(object s, MouseEventArgs e)
        {
            
        }
    }
}
#region 예제 1
//class MainApp : Form
//{
//    public void f1(object sender, MouseEventArgs e)
//    {
//        Console.WriteLine("click");
//        Console.WriteLine(((Form)sender).Text);
//        Console.WriteLine(e.X + " " + e.Y);
//        Console.WriteLine(e.Clicks); ;
//        Console.WriteLine();
//    }
//    public MainApp(string title)
//    {
//        this.Text = title;
//        this.MouseDown += new MouseEventHandler(f1);
//    }
//
//    static void Main(string[] args)
//    {
//        System.Windows.Forms.Application.Run(new MainApp("Mouse Event Test"));
//        //1번 예제
//        /*MyForm form = new MyForm();
//        form.Click += new EventHandler(
//            (snder, eventArgs) =>{
//                Console.WriteLine("종료 전");
//                Application.Exit();
//            });
//        Console.WriteLine("시작");
//        Application.Run(form);
//        Console.WriteLine("종료 후");*/
//    }
//}
#endregion
#region 예제 2
//class MainApp : Form
//{
//    public static void f1(object sender, MouseEventArgs e)
//    {
//        Form form = (Form)sender;
//        int oldWidth = form.Width;
//        int oldHeight = form.Height;
//
//        if (e.Button == MouseButtons.Left)
//        {
//            if (oldWidth < oldHeight)
//            {
//                form.Width = oldHeight;
//                form.Height = oldWidth;
//            }
//        }
//
//        if (e.Button == MouseButtons.Right)
//        {
//            if (oldHeight < oldWidth)
//            {
//                form.Width = oldHeight;
//                form.Height = oldWidth;
//            }
//        }
//    }
//
//
//    static void Main(string[] args)
//    {
//        MainApp form = new MainApp();
//        form.Width = 800;
//        form.Width = 600;
//        form.MouseDown += new MouseEventHandler(f1);
//        System.Windows.Forms.Application.Run(form);
//
//    }
//}
#endregion
#region 이벤트 발생시 사진 띄우는 예제(예제3)
/*class MainApp : Form
{
    Random rand;
    public MainApp()
    {
        rand = new Random();
        this.MouseWheel += new MouseEventHandler(f1);
        this.MouseDown += new MouseEventHandler(f2);
    }

    void f1(object sender, MouseEventArgs e) { }
    void f2(object sender, MouseEventArgs e)
    {
        string file = "sample.bmp";
        if (System.IO.File.Exists(file) == false)
        {
            Console.WriteLine("not found");
        }
        else
        {
            Console.WriteLine("found");
            this.BackgroundImage = Image.FromFile(file);
        }
    }

    static void Main(string[] args)
    {
        MainApp form = new MainApp();
        //        form.Width = 800;
        //        form.Width = 600;
        //        form.MouseDown += new MouseEventHandler(f1);
        System.Windows.Forms.Application.Run(form);
    }
}*/
#endregion
#region MyRegion
/*class MainApp : Form
{
    static void Main(string[] args)
    {
        MainApp form = new MainApp();
        form.Width = 400;
        form.MouseDown += new MouseEventHandler(f1);

        //MainApp form1 = new MainApp();
        //form1.Width = 400;
        //form1.MouseDown += new MouseEventHandler(f1);

        Application.Run(form);
    }

    static void f1(object s, MouseEventArgs e)
    {
        //Console.WriteLine( e );
        Form form = (Form)s;
        if (e.Button == MouseButtons.Left)
        {
            form.MaximizeBox = true;
            form.MinimizeBox = true;
            form.Text = "최대/최소 버튼 활성";
        }
        else if (e.Button == MouseButtons.Right)
        {
            form.MaximizeBox = false;
            form.MinimizeBox = false;
            form.Text = "최대/최소 버튼 비활성";
        }
    }
}*/
#endregion