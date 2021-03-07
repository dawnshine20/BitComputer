using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Oracle.ManagedDataAccess.Client;

// ProgressBar TrackBar
// TreeView
namespace MyWindowsFormsApp1
{
    public partial class Form1 : Form
    {
        //private string ConnectionString = "Data Source=192.168.35.48:1521/orcl;User Id=c##hsw;Password=1234;";
        private string ConnectionString = "Data Source=127.0.0.1:1521/orcl;User Id=c##lhb;Password=1234;";

        //Random random = new Random(100);
        static int index;

        public Form1()
        {
            InitializeComponent();

            listView1.BeginUpdate();

            listView1.View = View.Details;
            listView1.Columns.Add("Name",200, HorizontalAlignment.Right);
            listView1.Columns.Add("Age",200, HorizontalAlignment.Center);
            listView1.Columns.Add("Salary",200, HorizontalAlignment.Left);

            listView1.EndUpdate();
            #region 데이터 넣는 방법
            //// 방법1
            //string[] data = new string[] { "호랑이1", "코끼리", "독수리" };
            //ListViewItem lv = new ListViewItem(data);
            //listView1.Items.Add(lv);
            //
            //// 방법 2
            //lv = new ListViewItem(
            //    new string[] { "호랑이2", "코끼리", "독수리" }
            //    );
            //listView1.Items.Add(lv);
            //
            //// 방법 3
            //lv = new ListViewItem("호랑이3");
            //lv.SubItems.Add("코끼리");
            //lv.SubItems.Add("독수리");
            //listView1.Items.Add(lv);
            //
            //// 방법 4
            //listView1.Items.Add(new ListViewItem(
            //    new string[] { "호랑이4", "코끼리", "독수리" }
            //    ));
            #endregion

        }
        
        private void button4_Click(object sender, EventArgs e)
        {
            //string name = "호랑이" + random.Next();
            //listView1.Items.Add(new ListViewItem(
            //    new string[] { name, "코끼리", "독수리" }
            //));
            using (OracleConnection conn = new OracleConnection(ConnectionString))
            {
                conn.Open();

                // 명령 객체 생성
                OracleCommand command = new OracleCommand();
                command.Connection = conn;

                string name = textBox2.Text;
                int age = Convert.ToInt32(textBox3.Text);
                int sal = Convert.ToInt32(textBox4.Text);

                // SQL문 지정 및 INSERT 실행
                string query = $"INSERT INTO tab01 VALUES ('{name}',{age},{sal})";

                command.CommandText = query;
                command.ExecuteNonQuery();
                MessageBox.Show("insert 완료");

                conn.Close();
            }
                
            button5.PerformClick();
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //연결 객체 생성.
            using (OracleConnection connection = new OracleConnection(ConnectionString))
            {
                connection.Open();

                // 커맨드 객체 생성.
                OracleCommand command = new OracleCommand();
                command.Connection = connection;
                command.CommandText = "SELECT * FROM tab01";

                // 결과 리더 객체 리턴.
                OracleDataReader reader = command.ExecuteReader();
                // 리스트 뷰 초기화.
                listView1.Items.Clear();
                while (reader.Read())
                {
                    // 리스트 뷰 객체 생성.
                    ListViewItem lv = new ListViewItem();
                    // 리스트 뷰 객체 초기화.
                    lv.Text = reader[0].ToString();
                    for (int i = 1; i < listView1.Columns.Count; i++)
                        lv.SubItems.Add(reader[i].ToString());
                    // 리스트 추가.
                    listView1.Items.Add(lv);
                }

                reader.Close();
                // DB close.
                connection.Close();

                index = listView1.Items.Count - 1;
                listView1.Items[index].Focused = true;
                listView1.Items[index].Selected = true;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            using (OracleConnection conn = new OracleConnection(ConnectionString))
            {
                conn.Open();

                // 명령 객체 생성
                OracleCommand command = new OracleCommand();
                command.Connection = conn;

                string name = textBox2.Text;
                int age = Convert.ToInt32(textBox3.Text);
                int sal = Convert.ToInt32(textBox4.Text);

                // SQL문 지정 및 INSERT 실행
                //string query = $"UPDATE tab01 SET age = {age}, salary = {sal} WHERE name = '{name}'";
                string query = $"UPDATE tab01 SET age = {age}, salary = {sal} WHERE name = '{name}'";

                command.CommandText = query;
                command.ExecuteNonQuery();
                MessageBox.Show("update 완료");

                conn.Close();
            }

            button5.PerformClick();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            using (OracleConnection conn = new OracleConnection(ConnectionString))
            {
                conn.Open();

                // 명령 객체 생성
                OracleCommand command = new OracleCommand();
                command.Connection = conn;

                string name = textBox2.Text;

                // SQL문 지정 및 INSERT 실행
                string query = $"DELETE FROM tab01 WHERE name = '{name}'";

                command.CommandText = query;
                command.ExecuteNonQuery();
                MessageBox.Show("delete 완료");

                conn.Close();
            }

            button5.PerformClick();
        }


        //1521
        //-------------------------------------------------------
        private void Form1_Load(object sender, EventArgs e)
        {
            //MessageBox.Show("Form1_Load");
            var Fonts = FontFamily.Families;
            foreach(FontFamily item in Fonts)
            {
                comboBox1.Items.Add(item);
            }
        }
        
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e){ ChangeFont();}
        private void checkBox1_CheckedChanged(object sender, EventArgs e){ ChangeFont(); }
        private void checkBox2_CheckedChanged(object sender, EventArgs e){ ChangeFont(); }
        void ChangeFont()
        {
            if( comboBox1.SelectedIndex < 0)// 아무것도 선택되지 않을경우를 위한 예외처리
            {
                MessageBox.Show( "폰트 종류를 선택하세요" );
                return;
            }

            // 폰트스타일의 객체 초기화
            FontStyle style = FontStyle.Regular;
            if (checkBox1.Checked){style |= FontStyle.Bold;}
            if (checkBox2.Checked){style |= FontStyle.Italic;}

            textBox1.Font = new Font(
                (FontFamily)comboBox1.SelectedItem, 10, style
            );
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("1", "2", MessageBoxButtons.OK);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new Form();
            form.Text = "모달 폼";
            form.Width = 300;
            form.Height = 100;
            form.BackColor = Color.Red;
            form.ShowDialog();
        }
        
        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new Form();
            form.Text = "모달 폼";
            form.Width = 300;
            form.Height = 300;
            form.BackColor = Color.Green;
            form.Show();
        }

        
    }
}
