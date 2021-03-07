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
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void MenuItemSingleEmployee_Click(object sender, EventArgs e)
        {
            SingleEmployeeForm singleEmployeeForm = new SingleEmployeeForm();
            singleEmployeeForm.ShowDialog();
        }

        private void MenuItemAllEmployee_Click(object sender, EventArgs e)
        {
            AllEmployeesForm allEmployeesForm = new AllEmployeesForm();
            allEmployeesForm.ShowDialog();
        }

        private void MenuItemJobHistory_Click(object sender, EventArgs e)
        {
            JobHistoryForm jobHistoryForm = new JobHistoryForm();
            jobHistoryForm.ShowDialog();
        }

        private void ToolStripMenuItemEtcInfo_Click(object sender, EventArgs e)
        {
            GridForm infoForm = new GridForm();
            infoForm.ShowDialog();
        }
    }
}
