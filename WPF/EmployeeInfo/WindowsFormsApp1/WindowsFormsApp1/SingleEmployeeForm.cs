using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class SingleEmployeeForm : Form
    {
        public SingleEmployeeForm()
        {
            InitializeComponent();
        }

        private void BtnConfirm_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void BtnSearch_Click(object sender, EventArgs e)
        {
            Employee employee;

            employee = HrDAO.Instance.getEmployee(long.Parse(txtEmployeeId.Text));

            txtFirstName.Text = employee.First_name;
            txtLastName.Text = employee.Last_name;
            txtEmail.Text = employee.Email;
            txtPhoneNumber.Text = employee.Phone_number;
            txtHireDate.Text = employee.Hire_date.ToShortDateString();
            txtJobId.Text = employee.Job_id;
            txtSalary.Text = employee.Salary.ToString();
            txtCommissionPct.Text = employee.Commission_pct.ToString();
            txtManagerId.Text = employee.Manager_id.ToString();
            txtDepartmentId.Text = employee.Department_id.ToString();
        }

        private void SingleEmployeeForm_Load(object sender, EventArgs e)
        {

        }
    }
}
