using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class AllEmployeesForm : Form
    {
        public AllEmployeesForm()
        {
            InitializeComponent();
        }

        private void AllEmployeesForm_Load(object sender, EventArgs e)
        {
            lvEmployeeList.Columns.Add("사번");
            lvEmployeeList.Columns.Add("이름");
            lvEmployeeList.Columns.Add("전화번호");
            lvEmployeeList.Columns.Add("입사일");
            lvEmployeeList.Columns.Add("급여");

            lvEmployeeList.Columns[0].Width = 50;
            lvEmployeeList.Columns[0].TextAlign = HorizontalAlignment.Center;
            for (int i = 1; i < lvEmployeeList.Columns.Count; i++)
            {
                lvEmployeeList.Columns[i].Width = 100;
                lvEmployeeList.Columns[i].TextAlign = HorizontalAlignment.Center;
            }
        }

        private void BtnSearch_Click(object sender, EventArgs e)
        {
            ICollection<Employee> empList = HrDAO.Instance.getEmployeeList();
            ListViewItem item;
            foreach (Employee em in empList)
            {
                item = new ListViewItem(em.Employee_id.ToString());
                item.SubItems.Add(em.First_name + " " + em.Last_name);
                item.SubItems.Add(em.Phone_number);
                item.SubItems.Add(em.Hire_date.ToShortDateString());
                item.SubItems.Add(em.Salary.ToString());
                lvEmployeeList.Items.Add(item);
            }
        }

        private void BtnConfirm_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
