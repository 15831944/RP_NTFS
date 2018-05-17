namespace TestPQWin
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.txtCom = new System.Windows.Forms.TextBox();
            this.txtSpeed = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtMode = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtNode = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtNodeNum = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.btnSend = new System.Windows.Forms.Button();
            this.btnSelect = new System.Windows.Forms.Button();
            this.txtDir = new System.Windows.Forms.TextBox();
            this.txtFunctionTimeOut = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtUploadTimeOut = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.cbIsClearFile = new System.Windows.Forms.CheckBox();
            this.listView1 = new System.Windows.Forms.ListView();
            this.btnQuery = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.cbIsRepet = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(46, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "串口名称";
            // 
            // txtCom
            // 
            this.txtCom.Location = new System.Drawing.Point(118, 36);
            this.txtCom.Name = "txtCom";
            this.txtCom.Size = new System.Drawing.Size(100, 21);
            this.txtCom.TabIndex = 1;
            this.txtCom.Text = "COM3";
            // 
            // txtSpeed
            // 
            this.txtSpeed.Location = new System.Drawing.Point(118, 82);
            this.txtSpeed.Name = "txtSpeed";
            this.txtSpeed.Size = new System.Drawing.Size(100, 21);
            this.txtSpeed.TabIndex = 3;
            this.txtSpeed.Text = "3";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 85);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "速度标志";
            // 
            // txtMode
            // 
            this.txtMode.Location = new System.Drawing.Point(392, 85);
            this.txtMode.Name = "txtMode";
            this.txtMode.Size = new System.Drawing.Size(100, 21);
            this.txtMode.TabIndex = 5;
            this.txtMode.Text = "4";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(320, 88);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "工作方式";
            // 
            // txtNode
            // 
            this.txtNode.Location = new System.Drawing.Point(118, 132);
            this.txtNode.Name = "txtNode";
            this.txtNode.Size = new System.Drawing.Size(100, 21);
            this.txtNode.TabIndex = 7;
            this.txtNode.Text = "0";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(46, 135);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 12);
            this.label4.TabIndex = 6;
            this.label4.Text = "节点选择";
            // 
            // txtNodeNum
            // 
            this.txtNodeNum.Location = new System.Drawing.Point(392, 39);
            this.txtNodeNum.Name = "txtNodeNum";
            this.txtNodeNum.Size = new System.Drawing.Size(100, 21);
            this.txtNodeNum.TabIndex = 9;
            this.txtNodeNum.Text = "1";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(320, 42);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 8;
            this.label5.Text = "节点个数";
            // 
            // btnSend
            // 
            this.btnSend.Location = new System.Drawing.Point(40, 265);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(452, 51);
            this.btnSend.TabIndex = 10;
            this.btnSend.Text = "发送文件";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // btnSelect
            // 
            this.btnSelect.Location = new System.Drawing.Point(40, 182);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(75, 23);
            this.btnSelect.TabIndex = 11;
            this.btnSelect.Text = "选择路径";
            this.btnSelect.UseVisualStyleBackColor = true;
            this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
            // 
            // txtDir
            // 
            this.txtDir.Location = new System.Drawing.Point(138, 184);
            this.txtDir.Name = "txtDir";
            this.txtDir.ReadOnly = true;
            this.txtDir.Size = new System.Drawing.Size(354, 21);
            this.txtDir.TabIndex = 12;
            // 
            // txtFunctionTimeOut
            // 
            this.txtFunctionTimeOut.Location = new System.Drawing.Point(118, 228);
            this.txtFunctionTimeOut.Name = "txtFunctionTimeOut";
            this.txtFunctionTimeOut.Size = new System.Drawing.Size(100, 21);
            this.txtFunctionTimeOut.TabIndex = 14;
            this.txtFunctionTimeOut.Text = "20";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(46, 231);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 12);
            this.label6.TabIndex = 13;
            this.label6.Text = "函数延迟";
            // 
            // txtUploadTimeOut
            // 
            this.txtUploadTimeOut.Location = new System.Drawing.Point(392, 228);
            this.txtUploadTimeOut.Name = "txtUploadTimeOut";
            this.txtUploadTimeOut.Size = new System.Drawing.Size(100, 21);
            this.txtUploadTimeOut.TabIndex = 16;
            this.txtUploadTimeOut.Text = "0";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(320, 231);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 15;
            this.label7.Text = "上传延时";
            // 
            // cbIsClearFile
            // 
            this.cbIsClearFile.AutoSize = true;
            this.cbIsClearFile.Location = new System.Drawing.Point(322, 130);
            this.cbIsClearFile.Name = "cbIsClearFile";
            this.cbIsClearFile.Size = new System.Drawing.Size(72, 16);
            this.cbIsClearFile.TabIndex = 17;
            this.cbIsClearFile.Text = "清空文件";
            this.cbIsClearFile.UseVisualStyleBackColor = true;
            // 
            // listView1
            // 
            this.listView1.Location = new System.Drawing.Point(521, 82);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(334, 297);
            this.listView1.TabIndex = 19;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // btnQuery
            // 
            this.btnQuery.Location = new System.Drawing.Point(521, 33);
            this.btnQuery.Name = "btnQuery";
            this.btnQuery.Size = new System.Drawing.Size(137, 43);
            this.btnQuery.TabIndex = 20;
            this.btnQuery.Text = "查询";
            this.btnQuery.UseVisualStyleBackColor = true;
            this.btnQuery.Click += new System.EventHandler(this.btnQuery_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(718, 33);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(137, 43);
            this.btnClear.TabIndex = 21;
            this.btnClear.Text = "删除";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(40, 322);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(452, 51);
            this.button1.TabIndex = 22;
            this.button1.Text = "获取文件大小";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // cbIsRepet
            // 
            this.cbIsRepet.AutoSize = true;
            this.cbIsRepet.Location = new System.Drawing.Point(420, 130);
            this.cbIsRepet.Name = "cbIsRepet";
            this.cbIsRepet.Size = new System.Drawing.Size(72, 16);
            this.cbIsRepet.TabIndex = 23;
            this.cbIsRepet.Text = "重复上传";
            this.cbIsRepet.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(867, 381);
            this.Controls.Add(this.cbIsRepet);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnQuery);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.cbIsClearFile);
            this.Controls.Add(this.txtUploadTimeOut);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.txtFunctionTimeOut);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtDir);
            this.Controls.Add(this.btnSelect);
            this.Controls.Add(this.btnSend);
            this.Controls.Add(this.txtNodeNum);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtNode);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtMode);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtSpeed);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtCom);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "米尔迪克上传测试工具";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtCom;
        private System.Windows.Forms.TextBox txtSpeed;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtMode;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtNode;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtNodeNum;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.TextBox txtDir;
        private System.Windows.Forms.TextBox txtFunctionTimeOut;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtUploadTimeOut;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.CheckBox cbIsClearFile;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Button btnQuery;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.CheckBox cbIsRepet;
    }
}

