namespace WindowsFormsApp1
{
    partial class MainForm
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.MenuItemSearchEmployee = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemSingleEmployee = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemAllEmployee = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemHistory = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemJobHistory = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemInfo = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemEtcInfo = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemSearchEmployee,
            this.MenuItemHistory,
            this.ToolStripMenuItemInfo});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // MenuItemSearchEmployee
            // 
            this.MenuItemSearchEmployee.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemSingleEmployee,
            this.MenuItemAllEmployee});
            this.MenuItemSearchEmployee.Name = "MenuItemSearchEmployee";
            this.MenuItemSearchEmployee.Size = new System.Drawing.Size(67, 20);
            this.MenuItemSearchEmployee.Text = "직원조회";
            // 
            // MenuItemSingleEmployee
            // 
            this.MenuItemSingleEmployee.Name = "MenuItemSingleEmployee";
            this.MenuItemSingleEmployee.Size = new System.Drawing.Size(180, 22);
            this.MenuItemSingleEmployee.Text = "개별직원조회";
            this.MenuItemSingleEmployee.Click += new System.EventHandler(this.MenuItemSingleEmployee_Click);
            // 
            // MenuItemAllEmployee
            // 
            this.MenuItemAllEmployee.Name = "MenuItemAllEmployee";
            this.MenuItemAllEmployee.Size = new System.Drawing.Size(180, 22);
            this.MenuItemAllEmployee.Text = "모든직원조회";
            this.MenuItemAllEmployee.Click += new System.EventHandler(this.MenuItemAllEmployee_Click);
            // 
            // MenuItemHistory
            // 
            this.MenuItemHistory.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemJobHistory});
            this.MenuItemHistory.Name = "MenuItemHistory";
            this.MenuItemHistory.Size = new System.Drawing.Size(67, 20);
            this.MenuItemHistory.Text = "이력조회";
            // 
            // MenuItemJobHistory
            // 
            this.MenuItemJobHistory.Name = "MenuItemJobHistory";
            this.MenuItemJobHistory.Size = new System.Drawing.Size(180, 22);
            this.MenuItemJobHistory.Text = "이력조회";
            this.MenuItemJobHistory.Click += new System.EventHandler(this.MenuItemJobHistory_Click);
            // 
            // ToolStripMenuItemInfo
            // 
            this.ToolStripMenuItemInfo.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ToolStripMenuItemEtcInfo});
            this.ToolStripMenuItemInfo.Name = "ToolStripMenuItemInfo";
            this.ToolStripMenuItemInfo.Size = new System.Drawing.Size(67, 20);
            this.ToolStripMenuItemInfo.Text = "기타조회";
            // 
            // ToolStripMenuItemEtcInfo
            // 
            this.ToolStripMenuItemEtcInfo.Name = "ToolStripMenuItemEtcInfo";
            this.ToolStripMenuItemEtcInfo.Size = new System.Drawing.Size(180, 22);
            this.ToolStripMenuItemEtcInfo.Text = "기타정보조회";
            this.ToolStripMenuItemEtcInfo.Click += new System.EventHandler(this.ToolStripMenuItemEtcInfo_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem MenuItemSearchEmployee;
        private System.Windows.Forms.ToolStripMenuItem MenuItemSingleEmployee;
        private System.Windows.Forms.ToolStripMenuItem MenuItemAllEmployee;
        private System.Windows.Forms.ToolStripMenuItem MenuItemHistory;
        private System.Windows.Forms.ToolStripMenuItem MenuItemJobHistory;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemInfo;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemEtcInfo;
    }
}