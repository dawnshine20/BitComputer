using System;
using System.Collections.Generic;
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

namespace MyImageWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        //private void f1(object sender, RoutedEventArgs e)
        //{
        //    MessageBox.Show("1");
        //}
        //
        //private void f2(object sender, RoutedEventArgs e)
        //{
        //    MessageBox.Show("2");
        //}
        //
        //private void f3(object sender, RoutedEventArgs e)
        //{
        //    tb.FontWeight = FontWeights.Bold;
        //}
        //private void f4(object sender, RoutedEventArgs e)
        //{
        //    tb.FontWeight = FontWeights.Normal;
        //}
        //
        //private void f5(object sender, RoutedEventArgs e)
        //{
        //    tb.FontStyle = FontStyles.Italic;
        //}
        //private void f6(object sender, RoutedEventArgs e)
        //{
        //    tb.FontStyle = FontStyles.Normal;
        //}
        //
        //private void f7(object sender, RoutedEventArgs e)
        //{
        //    tb.FontSize += 3;
        //}


        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    MessageBox.Show("1");
        //    txt1.Text = "1";
        //}
        //private void StackPanel_Click(object sender, RoutedEventArgs e)
        //{
        //    MessageBox.Show("2");
        //    txt2.Text = "2";
        //
        //    //이 메세지는 나까지만 처리 되고 부모에게 전달되지 않는다.
        //    // 버블링을 멈출 때 사용한다.
        //    e.Handled = true;
        //}
        //private void Window_Click(object sender, RoutedEventArgs e)
        //{
        //    MessageBox.Show("3");
        //    txt3.Text = "3";
        //}
    }
}
