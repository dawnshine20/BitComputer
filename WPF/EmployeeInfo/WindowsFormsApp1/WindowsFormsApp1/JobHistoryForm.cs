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
    public partial class JobHistoryForm : Form
    {
        public JobHistoryForm()
        {
            InitializeComponent();
        }

        private void ButtonConfirm_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void JobHistoryForm_Load(object sender, EventArgs e)
        {
            lvHistory.Columns.Add("성명");
            lvHistory.Columns.Add("담당업무");
            lvHistory.Columns.Add("시작일");
            lvHistory.Columns.Add("종료일");
            for (int i = 0; i < lvHistory.Columns.Count; i++)
            {
                lvHistory.Columns[i].Width = 150;
                lvHistory.Columns[i].TextAlign = HorizontalAlignment.Center;
            }
        }

        private void BtnSearch_Click(object sender, EventArgs e)
        {
            ICollection<DataMapper> mapper = HrDAO.Instance.getHistory(int.Parse(txtEmployeeId.Text));
            ListViewItem item;
            foreach (DataMapper m in mapper)
            {
                item = new ListViewItem(m.StringValue1);
                item.SubItems.Add(m.StringValue2);
                item.SubItems.Add(m.DateTimeValue1.ToShortDateString());
                item.SubItems.Add(m.DateTimeValue2.ToShortDateString());
                lvHistory.Items.Add(item);
            }
        }
    }
}
