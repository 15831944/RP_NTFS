using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;
using TestPQCSharp;

namespace TestPQWin
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.FolderBrowserDialog fbd = new System.Windows.Forms.FolderBrowserDialog();
            if (fbd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                txtDir.Text = fbd.SelectedPath;
            }
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            try
            {
                string com = string.Format("{0},{1},{2},{3}", txtCom.Text, txtNodeNum.Text, txtSpeed.Text, txtMode.Text);
                Send(new List<string> { com ,txtNode.Text, txtDir.Text });
                MessageBox.Show("发送成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public void Send(List<string> args)
        {
            args.Insert(0, AppDomain.CurrentDomain.BaseDirectory);
            string format = "\"{0}\\TestPQCSharp.exe\"";
            for (int i = 1; i < args.Count; i++)
            {
                format += " \"{" + i + "}\"";
            }

            string str = string.Format(format
                , args.ToArray()
                );

            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = "cmd.exe";
            p.StartInfo.UseShellExecute = false;    //是否使用操作系统shell启动
            p.StartInfo.RedirectStandardInput = true;//接受来自调用程序的输入信息
            p.StartInfo.RedirectStandardOutput = true;//由调用程序获取输出信息
            p.StartInfo.RedirectStandardError = true;//重定向标准错误输出
            p.StartInfo.CreateNoWindow = true;//不显示程序窗口
            p.Start();//启动程序

            //向cmd窗口发送输入信息
            p.StandardInput.WriteLine(str + "&exit");

            p.StandardInput.AutoFlush = true;
            //p.StandardInput.WriteLine("exit");
            //向标准输入写入要执行的命令。这里使用&是批处理命令的符号，表示前面一个命令不管是否执行成功都执行后面(exit)命令，如果不执行exit命令，后面调用ReadToEnd()方法会假死
            //同类的符号还有&&和||前者表示必须前一个命令执行成功才会执行后面的命令，后者表示必须前一个命令执行失败才会执行后面的命令
            //获取cmd窗口的输出信息
            string output = p.StandardOutput.ReadToEnd();
            p.WaitForExit();//等待程序执行完退出进程
            p.Close();
            Console.WriteLine(output);
            var startStr = "&&FloppyTestPQCSharp&&";
            var index = output.IndexOf(startStr);
            var endIndex = output.IndexOf("&&EndFloppyTestPQCSharp&&");
            if (index >= 0&& endIndex>=0)
            {
                throw new Exception(output.Substring(index + startStr.Length, endIndex - index - startStr.Length));
            }
        }

        private void btnQuery_Click(object sender, EventArgs e)
        {
            try
            {
                Floppy.UploadTimeOut = int.Parse(txtUploadTimeOut.Text);
                Floppy.FunctionTimeOut = int.Parse(txtFunctionTimeOut.Text);
                Floppy.IsClearFile = cbIsClearFile.Checked;
                string com = string.Format("{0},{1},{2},{3}", txtCom.Text, txtNodeNum.Text, txtSpeed.Text, txtMode.Text);
                var str=new Floppy().QueryFunction(com, int.Parse(txtNode.Text));
                MessageBox.Show(str);
                listView1.Items.Clear();
                if (str != "2" && !string.IsNullOrEmpty(str)) 
                {
                    Console.Write("Length={0}", str.Length);
                    for (int i = 0; i < str.Length/12; i++)
                    {
                        var item = str.Substring(i * 12, 12);
                        Console.WriteLine(item);
                        Console.WriteLine("Item.Length={0}", item.Length);
                        var fileName = string.Format("{0}.{1}", item.Substring(0, 8).Trim(), item.Substring(8, 3).Trim());
                        listView1.Items.Add(item);
                    }
                   
                }
                MessageBox.Show("查询成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                if (listView1.SelectedItems.Count > 0) 
                {
                    Console.WriteLine("text ={0}  length={1}", listView1.SelectedItems[0].Text, listView1.SelectedItems[0].Text.Length);
                    Floppy.UploadTimeOut = int.Parse(txtUploadTimeOut.Text);
                    Floppy.FunctionTimeOut = int.Parse(txtFunctionTimeOut.Text);
                    Floppy.IsClearFile = cbIsClearFile.Checked;
                    Floppy.IsRepet = cbIsRepet.Checked;
                    string com = string.Format("{0},{1},{2},{3}", txtCom.Text, txtNodeNum.Text, txtSpeed.Text, txtMode.Text);
                    new Floppy().DeleteFunction(com, int.Parse(txtNode.Text), listView1.SelectedItems[0].Text);
                    MessageBox.Show("删除成功");
                }
              
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            if (file.ShowDialog() == DialogResult.OK) 
            {
                var name = file.FileName;
                var info = new FileInfo(name);
                MessageBox.Show(info.Length.ToString());
            }
        }
    }
}
