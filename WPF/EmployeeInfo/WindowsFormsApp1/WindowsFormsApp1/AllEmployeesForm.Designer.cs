namespace WindowsFormsApp1
{
    partial class AllEmployeesForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBoxSearch = new System.Windows.Forms.GroupBox();
            this.groupBoxResult = new System.Windows.Forms.GroupBox();
            this.btnConfirm = new System.Windows.Forms.Button();
            this.btnSearch = new System.Windows.Forms.Button();
            this.lvEmployeeList = new System.Windows.Forms.ListView();
            this.groupBoxSearch.SuspendLayout();
            this.groupBoxResult.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxSearch
            // 
            this.groupBoxSearch.Controls.Add(this.btnSearch);
            this.groupBoxSearch.Location = new System.Drawing.Point(17, 11);
            this.groupBoxSearch.Name = "groupBoxSearch";
            this.groupBoxSearch.Size = new System.Drawing.Size(770, 71);
            this.groupBoxSearch.TabIndex = 0;
            this.groupBoxSearch.TabStop = false;
            this.groupBoxSearch.Text = "[조회]";
            // 
            // groupBoxResult
            // 
            this.groupBoxResult.Controls.Add(this.lvEmployeeList);
            this.groupBoxResult.Location = new System.Drawing.Point(16, 95);
            this.groupBoxResult.Name = "groupBoxResult";
            this.groupBoxResult.Size = new System.Drawing.Size(770, 292);
            this.groupBoxResult.TabIndex = 1;
            this.groupBoxResult.TabStop = false;
            this.groupBoxResult.Text = "[조회결과]";
            // 
            // btnConfirm
            // 
            this.btnConfirm.Location = new System.Drawing.Point(655, 404);
            this.btnConfirm.Name = "btnConfirm";
            this.btnConfirm.Size = new System.Drawing.Size(130, 31);
            this.btnConfirm.TabIndex = 2;
            this.btnConfirm.Text = "확 인";
            this.btnConfirm.UseVisualStyleBackColor = true;
            this.btnConfirm.Click += new System.EventHandler(this.BtnConfirm_Click);
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(622, 20);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(130, 31);
            this.btnSearch.TabIndex = 3;
            this.btnSearch.Text = "조 회";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.BtnSearch_Click);
            // 
            // lvEmployeeList
            // 
            this.lvEmployeeList.HideSelection = false;
            this.lvEmployeeList.Location = new System.Drawing.Point(12, 22);
            this.lvEmployeeList.Name = "lvEmployeeList";
            this.lvEmployeeList.Size = new System.Drawing.Size(740, 255);
            this.lvEmployeeList.TabIndex = 0;
            this.lvEmployeeList.UseCompatibleStateImageBehavior = false;
            this.lvEmployeeList.View = System.Windows.Forms.View.Details;
            // 
            // AllEmployeesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnConfirm);
            this.Controls.Add(this.groupBoxResult);
            this.Controls.Add(this.groupBoxSearch);
            this.Name = "AllEmployeesForm";
            this.Text = "AllEmployeesForm";
            this.Load += new System.EventHandler(this.AllEmployeesForm_Load);
            this.groupBoxSearch.ResumeLayout(false);
            this.groupBoxResult.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxSearch;
        private System.Windows.Forms.GroupBox groupBoxResult;
        private System.Windows.Forms.Button btnConfirm;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.ListView lvEmployeeList;
    }
}