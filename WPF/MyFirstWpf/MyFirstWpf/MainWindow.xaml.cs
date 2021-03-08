using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace MyFirstWpf
{
    #region Backup1
    ///// <summary>
    ///// MainWindow.xaml에 대한 상호 작용 논리
    ///// </summary>
    //public class Person
    //{
    //    //private string nameValue;
    //    //public string Name 
    //    //{
    //    //    get { return nameValue; }
    //    //    set { nameValue = value; }
    //    //}
    //    //private double ageValue;
    //    //public double Age 
    //    //{
    //    //    get{ return ageValue; }
    //    //    set
    //    //    {
    //    //        if(value != ageValue)
    //    //        {
    //    //            ageValue = value;
    //    //        }
    //    //    }
    //    //}
    //    //--------------------------------
    //    public string Name { get; set; }
    //    public double Age { get; set; }
    //}
    //public partial class MainWindow : Window
    //{
    //    Person person = new Person { Name = "호랑이", Age = 30 };
    //    public MainWindow()
    //    {
    //        InitializeComponent();
    //        #region 그리드 초기 버튼 만들기
    //        //Grid grid = new Grid();
    //        //this.Content = grid;
    //        //
    //        //Button button = new Button();
    //        //button.Content = "호랑이";
    //        //button.HorizontalAlignment = HorizontalAlignment.Left;
    //        //button.Margin = new Thickness(150);
    //        //button.VerticalAlignment = VerticalAlignment.Top;
    //        //button.Width = 75;
    //        //grid.Children.Add(button);
    //        #endregion
    //        this.DataContext = person;
    //    }
    //    #region 버튼 예제
    //    //private void Button_Click(object sender, RoutedEventArgs e)
    //    //{
    //    //    //MessageBox.Show("1", "캡션");
    //    //    //MessageBoxResult result1 = MessageBox.Show("2", "캡션", MessageBoxButton.YesNoCancel);
    //    //    //if (result1 == MessageBoxResult.Yes)
    //    //    //{
    //    //    //    MessageBox.Show("Yes");
    //    //    //}
    //    //    //else if (result1 == MessageBoxResult.No)
    //    //    //{
    //    //    //    MessageBox.Show("No");
    //    //    //}
    //    //    //else
    //    //    //{
    //    //    //    MessageBox.Show("Cancel");
    //    //    //}
    //    //    MessageBox.Show("6", "캡션", MessageBoxButton.OK, MessageBoxImage.Exclamation, MessageBoxResult.OK);
    //    //}
    //    //
    //    //private void Button1_Click(object sender, RoutedEventArgs e)
    //    //{
    //    //    //MessageBox.Show("2");
    //    //    // ex1)
    //    //    // Button1.Background = Brushes.Green;
    //    //    // ex2)
    //    //    //Button.IsEnabled = !Button.IsEnabled;
    //    //    // ex3)
    //    //    //if (Button.IsVisible )
    //    //    //    //Button.Visibility = Visibility.Hidden;
    //    //    //    Button.Visibility = Visibility.Collapsed; // width랑 height를 아예 0으로 만들어보인다.
    //    //    //else
    //    //    //    Button.Visibility = Visibility.Visible;
    //    //    // ex4)
    //    //    // if(Button.Content.ToString() == "호랑이")
    //    //    //     Button.Content = "독수리";
    //    //    // else
    //    //    //     Button.Content = "호랑이";
    //    //}
    //    #endregion
    //
    //    #region 버튼 이벤트 예제
    //    //private void f1(object sender, RoutedEventArgs e)
    //    //{
    //    //    Button btn = sender as Button;
    //    //    this.Title = btn.Content.ToString();
    //    //
    //    //
    //    //    //MessageBox.Show(btn.Name);
    //    //    //MessageBox.Show($"{btn.Name}");
    //    //    //MessageBox.Show(btn.Content.ToString());
    //    //}
    //    //
    //    //private void Window_MouseMove(object sender, MouseEventArgs e)
    //    //{
    //    //    Point pt = e.GetPosition(this);
    //    //    this.Title = $"{pt.X} {pt.Y}";
    //    //}
    //    //
    //    //private void f2(object sender, RoutedEventArgs e)
    //    //{
    //    //    //this.Background = new SolidColorBrush(Color.FromArgb(0xff, 0xff, 0xff, 0x23));
    //    //    Console.WriteLine("디버깅"); // F5 사용
    //    //
    //    //    Button btn = sender as Button;
    //    //    //btn.Background = ;
    //    //    //1 Background    2 BorderBrush     3 BorderThickness
    //    //    //4 Content       5 ClickMode       6 ContentTemplate
    //    //    //7 FontFamily    8 FontSize        9 FontStyle
    //    //    //10 FontWeight   11 Foreground     12 Height
    //    //    //13 HorizontalAlignment            14 IsEnabled
    //    //    //15 IsPressed    16 Margin         17 Name
    //    //    //18 Opacity      19 Resources      20 Style
    //    //    //21 Template     22 VerticalAlignment
    //    //    //23 Visibility   24 Width
    //    //
    //    //}
    //    #endregion
    //    #region 컨트롤 이벤트 예제
    //    //private void textBlock_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
    //    //{
    //    //    MessageBox.Show("1");
    //    //}
    //    //
    //    //private void Button_Click(object sender, RoutedEventArgs e)
    //    //{
    //    //    MessageBox.Show("Click");
    //    //}
    //    //
    //    //private void ListBoxItem_Selected(object sender, RoutedEventArgs e)
    //    //{
    //    //    ListBoxItem listBoxItem = e.Source as ListBoxItem;
    //    //    MessageBox.Show(listBoxItem.Content.ToString());
    //    //}
    //    #endregion
    //    private void f1(object sender, RoutedEventArgs e)
    //    {
    //        string message = person.Name + " " + person.Age;
    //        MessageBox.Show(message);
    //    }
    //    private void f2(object sender, RoutedEventArgs e)
    //    {
    //        //// 1. 데이터 직접 넣는다.( 바인드와 관계가 없다.
    //        //nameText.Text = "독수리";
    //        //ageText.Text = "999";
    //        //
    //        //// 2. 잘못된 방향
    //        //person = new Person();
    //        //person.Name = "독수리";
    //        //person.Age = 999;
    //        //this.DataContext = person;
    //
    //        // 3.person 객체의 값이 바뀌면 UI가 자동 갱신.
    //        //person.Name = "독수리";
    //        //person.Age = 999;
    //        //
    //        //this.DataContext = null;
    //        //this.DataContext = person;
    //
    //        //4.
    //
    //    }
    //}
    #endregion
    #region BackUp2
    // 관리자가 추가, 수정, 삭제 될때마다 변동된 데이터를 바로 전체 프로그램에 반영 시키고 싶을 경우
    //class Person : INotifyPropertyChanged
    //{
    //    private string name;
    //    public string Name
    //    {
    //        get { return name; }
    //        set
    //        {
    //            name = value;
    //            OnPropertyChanged("Name");
    //        }
    //    }
    //
    //    private int age;
    //    public int Age
    //    {
    //        get { return age; }
    //        set
    //        {
    //            age = value;
    //            OnPropertyChanged("Age");
    //        }
    //    }
    //
    //    public event PropertyChangedEventHandler PropertyChanged; // 이벤트(델리게이트(함수) 등록)
    //    // OnPropertyChanged에서 특정 이벤트란 프로퍼티가 갖는 데이터에 변화가 생길 때를 뜻함
    //    protected virtual void OnPropertyChanged(string propertyName)
    //    {
    //        // 연결된 에디터 박스에 값 변경 실행
    //        // Invoke : 스레드로부터 안전한 방식으로 Windows Forms 컨트롤을 호출
    //        // 다른 스레드에서 이 윈도우에 접근하려 할 경우 에러가 생기는데 그것을 막아주는 역할을 시도한다.
    //        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    //        // ?. <-- null이 반환될 경우 실행되지 않음
    //        // 바인딩 된 데이터가 반환된 경우 바인딩 된 에디터 박스에 프로퍼티 데이터로 갱신화 진행
    //    }
    //}
    //public partial class MainWindow : Window
    //{
    //    Person person = new Person { Name = "고양이", Age = 20 };
    //
    //    public MainWindow()
    //    {
    //        InitializeComponent();
    //        this.DataContext = person; // 에디터 박스와 클래스 데이터를 연결(바인딩)
    //    }
    //
    //    private void Button_Click1(object sender, RoutedEventArgs e)
    //    {
    //        MessageBox.Show(person.Name + " " + person.Age);
    //    }
    //    //                      view   객체(person)
    //    // TwoWay                   <-->
    //    // OneWay                   <--
    //    // OneWayTwoSource           -->
    //
    //    // TwoWay 사용할 경우 view 데이터 변경시 바로 객체에 적용된다.
    //    // OneWay 사용할 경우 객체 내부 데이터를 직접적으로 변경해 주어야 적용된다.
    //
    //    private void Button_Click2(object sender, RoutedEventArgs e)
    //    {
    //        person.Name = "독수리";
    //        person.Age = 999;
    //    }
    //}
    #endregion
    #region BackUp3(mouse,keboard)
    //public partial class MainWindow : Window
    //{
    //    public MainWindow()
    //    {
    //        InitializeComponent();
    //    }
    //
    //    private void OnMouseEnter(object sender, MouseEventArgs e)
    //    {
    //        Rectangle rect = e.Source as Rectangle;
    //        if(rect != null)
    //        {
    //            rect.Fill = Brushes.Blue;
    //        }
    //        textBlock.Text = "MouseEnter";
    //    }
    //
    //    private void OnMouseLeave(object sender, MouseEventArgs e)
    //    {
    //        Rectangle rect = e.Source as Rectangle;
    //        if (rect != null)
    //        {
    //            rect.Fill = Brushes.Green;
    //        }
    //        textBlock.Text = "MouseLeave";
    //        textBlock1.Text = "";
    //    }
    //
    //    private void OnMouseMove(object sender, MouseEventArgs e)
    //    {
    //        Point pt = e.GetPosition(rect01);
    //        textBlock1.Text = "Mouse Move : " + pt.ToString();
    //    }
    //
    //    private void OnMouseDown(object sender, MouseButtonEventArgs e)
    //    {
    //        Rectangle rect = e.Source as Rectangle;
    //        Point pt = e.GetPosition(rect01);
    //        textBlock2.Text = "Mouse Down : " + pt.ToString();
    //        if (rect != null)
    //        {
    //            rect.Fill = Brushes.Red;
    //        }
    //    }
    //}
    //---------------------------------------------------------------
    //public partial class MainWindow : Window
    //{
    //    public MainWindow()
    //    {
    //        InitializeComponent();
    //    }
    //    
    //    private void OnTextInputKeyDown(object sender, KeyEventArgs e)
    //    {
    //        if (e.Key == Key.A)
    //        {
    //            MessageBox.Show("KeyDown");
    //        }
    //    }
    //
    //    private void OnTextInputButtonClick(object sender, RoutedEventArgs e)
    //    {
    //        MessageBox.Show("TextInputButtonClick");
    //    }
    //}
    #endregion
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            CommandBindings.Add(new CommandBinding(
                ApplicationCommands.New, NewExecuted, null));
            CommandBindings.Add(new CommandBinding(
                ApplicationCommands.New, OpenExecuted, null));
        }

        private void NewExecuted(object sender, ExecutedRoutedEventArgs e)
        {
            MessageBox.Show("NewExecuted");
        }
        private void OpenExecuted(object sender, ExecutedRoutedEventArgs e)
        {
            MessageBox.Show("OpenExecuted");
        }
        private void SaveExecuted(object sender, ExecutedRoutedEventArgs e)
        {
            MessageBox.Show("SaveExecuted");
        }
    }

}
