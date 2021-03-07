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
    //    //    
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
    class Person : INotifyPropertyChanged
    {
        private string name;
        public string Name
        {
            get { return name; }
            set { name = value; OnPropertyChanged("Name"); }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
    public partial class MainWindow : Window
    {
        Person person = new Person { Name = "호랑이" };
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = person;
        }
        private void Button_Click1(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(person.Name);
        }
        //                      view   객체(person)
        // TwoWay                   <-->
        // OneWay                   <--
        // OneWayTwoSource           -->
        
        // TwoWay 사용할 경우 view 데이터 변경시 바로 객체에 적용된다.
        // OneWay 사용할 경우 객체 내부 데이터를 직접적으로 변경해 주어야 적용된다.

        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            person.Name = "독수리";
        }
    }
}
