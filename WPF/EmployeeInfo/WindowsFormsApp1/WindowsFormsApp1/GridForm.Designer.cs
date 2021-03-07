namespace WindowsFormsApp1
{
    partial class GridForm
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.groupBoxLocation = new System.Windows.Forms.GroupBox();
            this.groupBoxJobs = new System.Windows.Forms.GroupBox();
            this.btnLocation = new System.Windows.Forms.Button();
            this.dataGridViewLocation = new System.Windows.Forms.DataGridView();
            this.btnClose = new System.Windows.Forms.Button();
            this.dataGridViewJobs = new System.Windows.Forms.DataGridView();
            this.groupBoxLocation.SuspendLayout();
            this.groupBoxJobs.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewLocation)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewJobs)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBoxLocation
            // 
            this.groupBoxLocation.Controls.Add(this.dataGridViewLocation);
            this.groupBoxLocation.Controls.Add(this.btnLocation);
            this.groupBoxLocation.Location = new System.Drawing.Point(20, 17);
            this.groupBoxLocation.Name = "groupBoxLocation";
            this.groupBoxLocation.Size = new System.Drawing.Size(1079, 274);
            this.groupBoxLocation.TabIndex = 0;
            this.groupBoxLocation.TabStop = false;
            this.groupBoxLocation.Text = "[Location]";
            // 
            // groupBoxJobs
            // 
            this.groupBoxJobs.Controls.Add(this.dataGridViewJobs);
            this.groupBoxJobs.Location = new System.Drawing.Point(20, 297);
            this.groupBoxJobs.Name = "groupBoxJobs";
            this.groupBoxJobs.Size = new System.Drawing.Size(1079, 274);
            this.groupBoxJobs.TabIndex = 1;
            this.groupBoxJobs.TabStop = false;
            this.groupBoxJobs.Text = "[Jobs]";
            // 
            // btnLocation
            // 
            this.btnLocation.Location = new System.Drawing.Point(969, 27);
            this.btnLocation.Name = "btnLocation";
            this.btnLocation.Size = new System.Drawing.Size(97, 34);
            this.btnLocation.TabIndex = 0;
            this.btnLocation.Text = "조 회";
            this.btnLocation.UseVisualStyleBackColor = true;
            this.btnLocation.Click += new System.EventHandler(this.BtnLocation_Click);
            // 
            // dataGridViewLocation
            // 
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewLocation.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewLocation.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewLocation.Location = new System.Drawing.Point(22, 24);
            this.dataGridViewLocation.Name = "dataGridViewLocation";
            this.dataGridViewLocation.RowTemplate.Height = 23;
            this.dataGridViewLocation.Size = new System.Drawing.Size(929, 238);
            this.dataGridViewLocation.TabIndex = 1;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(989, 584);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(97, 34);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "닫 기";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.BtnClose_Click);
            // 
            // dataGridViewJobs
            // 
            this.dataGridViewJobs.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewJobs.Location = new System.Drawing.Point(25, 24);
            this.dataGridViewJobs.Name = "dataGridViewJobs";
            this.dataGridViewJobs.RowTemplate.Height = 23;
            this.dataGridViewJobs.Size = new System.Drawing.Size(925, 232);
            this.dataGridViewJobs.TabIndex = 0;
            // 
            // GridForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1120, 630);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.groupBoxJobs);
            this.Controls.Add(this.groupBoxLocation);
            this.Name = "GridForm";
            this.Text = "기타정보";
            this.Load += new System.EventHandler(this.GridForm_Load);
            this.groupBoxLocation.ResumeLayout(false);
            this.groupBoxJobs.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewLocation)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewJobs)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxLocation;
        private System.Windows.Forms.Button btnLocation;
        private System.Windows.Forms.GroupBox groupBoxJobs;
        private System.Windows.Forms.DataGridView dataGridViewLocation;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.DataGridView dataGridViewJobs;
    }
}