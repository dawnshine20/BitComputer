using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
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

namespace MySecondWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        List<string> imgList = new List<string>();
        List<Image> imgCtrolList = new List<Image>();
        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Folder Button 클릭 이벤트 핸들러
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button_Folder_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            
            if(ofd.ShowDialog() == true)
            {
                string fullPath = ofd.FileName; // 경로이름 저장
                string fileName = ofd.SafeFileName; // 파일 이름 저장
                // 전체 경로에서 파일이름 부분만 뺀 순수 경로를 추출한다.
                string path = fullPath.Replace(fileName, "");  

                uiTxt_Folder.Text = path;

                string[] files = Directory.GetFiles(path); // 경로 디렉토리에 있는 모든 파일을 불러온다.
                
                // 전체 파일 중 .jpg와 .png가 붙은 파일만 추출
                imgList = files.Where(x => 
                x.IndexOf(".jpg", StringComparison.OrdinalIgnoreCase) >= 0
                || x.IndexOf(".png", StringComparison.OrdinalIgnoreCase) >= 0)
                    .Select(x => x).ToList();
            }
            CreateImage(imgList); //이미지 파일명 모두 전달
        }

        /// <summary>
        /// 이미지 클릭 이벤트 핸들러
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ImageButton_Click(object sender, MouseButtonEventArgs e)
        {
            Image image = sender as Image;

            CreateBitmap(image, image.Source.ToString());

            ((image.Parent) as WrapPanel).Children.Clear();

            image.Stretch = Stretch.UniformToFill;
            uiCanvas_Image.Children.Clear();
            uiCanvas_Image.Children.Add(image);

            CreateImage(imgList);
        }

        /// <summary>
        /// 이미지 생성 메서드
        /// </summary>
        /// <param name="imgList"></param>
        private void CreateImage(List<string> imgList)
        {
            for (int i = 0; i < imgList.Count; i++)
            {
                Image image = new Image();

                CreateBitmap(image, imgList[i]);

                imgCtrolList.Add(image);

                image.MouseDown += ImageButton_Click;
                uiWrap_Image.Children.Add(image);
            }
        }

        /// <summary>
        /// 비트맵 이미지 생성 메서드
        /// </summary>
        /// <param name="image"></param>
        /// <param name="imageList"></param>
        private void CreateBitmap(Image image, string imageList)
        {
            BitmapImage img = new BitmapImage();
            img.BeginInit();
            img.CacheOption = BitmapCacheOption.OnDemand;
            img.CreateOptions = BitmapCreateOptions.DelayCreation;
            img.DecodePixelWidth = 300;
            img.UriSource = new Uri(imageList.ToString());
            img.EndInit();
            image.Source = img;
        }
    }
}
