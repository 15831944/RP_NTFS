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
                Floppy.UploadTimeOut = int.Parse(txtUploadTimeOut.Text);
                Floppy.FunctionTimeOut = int.Parse(txtFunctionTimeOut.Text);
                Floppy.IsClearFile = cbIsClearFile.Checked;
                Floppy.IsRepet = cbIsRepet.Checked;
                DirectoryInfo info = new DirectoryInfo(txtDir.Text);
                string com = string.Format("{0},{1},{2},{3}", txtCom.Text, txtNodeNum.Text, txtSpeed.Text, txtMode.Text);
                new Floppy().SendFuction(com, int.Parse(txtNode.Text), info);
                MessageBox.Show("发送成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
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
