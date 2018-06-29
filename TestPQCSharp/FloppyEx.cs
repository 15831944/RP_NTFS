using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace TestPQCSharp
{
    public class FloppyEx
    {
        #region 系统变量

        List<string> List_Com = new List<string>();

        List<String> newFile = new List<string>();

        List<string> oldFile = new List<string>();

        #endregion

        #region  调用c++ 库
        [DllImport("TestPQ.dll")]
        public static extern int TestInitializeFuction(string m_Way, int NodeNum, int Speed, int Mode);

        [DllImport("TestPQ.dll")]
        public static extern int TestUnInitializeFuction();

        [DllImport("TestPQ.dll")]
        public static extern int TestSendFuction(string m_StrPath, int Num);

        [DllImport("TestPQ.dll")]
        public static extern int TestClearFuction(int Num);

        [DllImport("TestPQ.dll")]
        public static extern string TestQueryFunction(int Num);
        [DllImport("TestPQ.dll")]
        public static extern int TestDeleteFunction(int Num, string fileName);
        #endregion

        #region 文件上传
        public static int FunctionTimeOut = 20;
        public static int UploadTimeOut = 0;
        public static bool IsClearFile = true;
        public static bool IsRepet = false;
        /// <summary>
        /// 批量上传文件
        /// </summary>
        /// <param name="COM">COM节点</param>
        /// <param name="Node">节点通道个数</param>
        /// <param name="FilePath">文件副本的List集合</param>
        /// <returns>0：初始化失败;1:正确;-1:文件路径错误;2:文件阻塞</returns>
        public void SendFuction(string COM, int Node, DirectoryInfo DirInfo)
        {
            int timeOut = FunctionTimeOut;
            if (IsClearFile)
            {
                //初始化串口
                if (InitializeFuction(COM) == 0)
                {
                    throw new Exception("初始化机台串口失败");
                }
                System.Threading.Thread.Sleep(timeOut);
                var str = TestQueryFunction(Node);
                // 查询文件
                switch (str)
                {
                    case "2":
                        throw new Exception("查询机台文件失败1");
                }
                System.Threading.Thread.Sleep(timeOut);

                for (int i = 0; i < str.Length / 12; i++)
                {
                    var item = str.Substring(i * 12, 12);
                    //初始化串口
                    if (InitializeFuction(COM) == 0)
                    {
                        throw new Exception("初始化机台串口失败");
                    }
                    System.Threading.Thread.Sleep(timeOut);
                    // 清空文件
                    switch (TestDeleteFunction(Node, item))
                    {
                        case 0:
                            throw new Exception("清空机台文件失败1");
                        case 2:
                            throw new Exception("清空机台文件失败");
                    }
                    System.Threading.Thread.Sleep(timeOut);
                }
            }

            //初始化串口
            if (InitializeFuction(COM) == 0)
            {
                throw new Exception("初始化机台串口失败");
            }
            System.Threading.Thread.Sleep(timeOut);
            TestUnInitializeFuction();

            for (int i = 1; i <= (IsRepet ? 2 : 1); i++)
            {
                Console.WriteLine();
                Console.WriteLine(string.Format("第{0}次上传", i));
                Console.WriteLine();
                foreach (FileInfo f in DirInfo.GetFiles())
                {
                    System.Threading.Thread.Sleep(timeOut);
                    //初始化串口
                    if (InitializeFuction(COM) == 0)
                    {
                        throw new Exception("初始化机台串口失败");
                    }
                    System.Threading.Thread.Sleep(timeOut);
                    //上传文件 无论上传成功或者失败,都要将副本全部删除
                    int result = TestSendFuction(f.FullName, Node);
                    switch (result)
                    {
                        case 0:
                            throw new Exception("文件:" + f.Name + "上传失败");
                        case 2: // 2 ：超时,文件阻塞
                            throw new Exception("文件:" + f.Name + "上传发生阻塞");
                        default:
                            Console.WriteLine("hello:" + result);
                            break;
                    }
                    System.Threading.Thread.Sleep(UploadTimeOut);
                    System.Threading.Thread.Sleep(timeOut);

                    //初始化串口
                    if (InitializeFuction(COM) == 0)
                    {
                        throw new Exception("初始化机台串口失败");
                    }
                    System.Threading.Thread.Sleep(timeOut);
                    TestUnInitializeFuction();

                }
            }
        }
        #endregion

        #region  查询文件
        /// <summary>
        /// 查询文件
        /// </summary>
        public String QueryFunction(string COM, int Node)
        {
            int timeOut = FunctionTimeOut;
            //初始化串口
            if (InitializeFuction(COM) == 0)
            {
                throw new Exception("初始化机台串口失败");
            }
            System.Threading.Thread.Sleep(timeOut);
            var str = TestQueryFunction(Node);
            // 查询文件
            switch (str)
            {
                case "2":
                    throw new Exception("查询机台文件失败1");
            }
            System.Threading.Thread.Sleep(timeOut);

            //初始化串口
            if (InitializeFuction(COM) == 0)
            {
                throw new Exception("初始化机台串口失败");
            }
            System.Threading.Thread.Sleep(timeOut);
            TestUnInitializeFuction();

            return str;
        }
        #endregion

        #region  删除节点文件
        /// <summary>
        /// 删除节点文件
        /// </summary>
        public void DeleteFunction(string COM, int Node, string fileName)
        {
            int timeOut = FunctionTimeOut;
            //初始化串口
            if (InitializeFuction(COM) == 0)
            {
                throw new Exception("初始化机台串口失败");
            }
            System.Threading.Thread.Sleep(timeOut);
            // 清空文件
            switch (TestDeleteFunction(Node, fileName))
            {
                case 0:
                    throw new Exception("查询机台文件失败1");
                case 2:
                    throw new Exception("查询机台文件失败");
            }
            System.Threading.Thread.Sleep(timeOut);

            //初始化串口
            if (InitializeFuction(COM) == 0)
            {
                throw new Exception("初始化机台串口失败");
            }
            System.Threading.Thread.Sleep(timeOut);
            TestUnInitializeFuction();
        }
        #endregion

        #region 清空文件
        /// <summary>
        /// 清空文件
        /// </summary>
        /// <param name="COM">COM节点</param>
        /// <param name="Node">节点通道个数</param>
        /// <param name="FilePath">源文件路径</param>
        /// <returns>0：清空文件失败;1:正确;2:文件阻塞</returns>
        private int ClearFuction(string COM, int Node)
        {
            switch (InitializeFuction(COM))//初始化 串口
            {
                case 0:
                    return 0;  // 0 ：初始化 失败
            }
            switch (TestClearFuction(Node))
            {
                case 0:
                    return 0;  // 0 ：清空文件失败
                case 2:
                    return 2;  // 2 ：文件阻塞
            }
            return 1;
        }
        #endregion

        #region 初始化串口
        /// <summary>
        /// 初始化串口
        /// </summary>
        /// <param name="COM">节点字符串</param>
        /// <returns>0：初始化串口失败;1:正确</returns>
        private int InitializeFuction(string COM)
        {
            List_Com.Clear();
            foreach (var i in COM.Split(','))
            {
                List_Com.Add(i);
            }

            //初始化串口
            if (TestInitializeFuction(List_Com[0], Convert.ToInt32(List_Com[1]), Convert.ToInt32(List_Com[2]), Convert.ToInt32(List_Com[3])) == 0)
            {
                return 0; // 0 ：初始化串口失败
            };
            return 1;
        }
        #endregion

        public void FileUp(string COM, string fullFileName)
        {

        }
    }
}
