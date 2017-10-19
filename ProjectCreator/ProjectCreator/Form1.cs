using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProjectCreator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ProjectPathButton_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.ShowDialog();
            ProjectPathText.Text = fbd.SelectedPath.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (CheckEmptyBox())
            {
                string enginePath = Environment.GetEnvironmentVariable("CotEngine", EnvironmentVariableTarget.User);
                string projectSolutionPath = string.Format("{0}\\{1}", ProjectPathText.Text, ProjectNameText.Text);
                string projectPath = string.Format("{0}\\{1}", projectSolutionPath, ProjectNameText.Text);
                string projectClassPath = string.Format("{0}\\Classes", projectSolutionPath);

                #region 디렉토리 생성
                // 솔루션 파일
                DirectoryInfo dirInfo = null;
                dirInfo = new DirectoryInfo(projectSolutionPath);
                if (!dirInfo.Exists)
                {
                    dirInfo.Create();
                }

                // 프로젝트 파일
                dirInfo = new DirectoryInfo(projectPath);
                if (!dirInfo.Exists)
                {
                    dirInfo.Create();
                }

                // Classes 폴더
                dirInfo = new DirectoryInfo(projectClassPath);
                if (!dirInfo.Exists)
                {
                    dirInfo.Create();
                }
                #endregion

                string solution = string.Format("{0}template\\Template.sln", enginePath);
                string project = string.Format("{0}template\\Template\\Template.vcxproj", enginePath);
                string projectFilter = string.Format("{0}template\\Template\\Template.vcxproj.filters", enginePath);
                string mainCpp = string.Format("{0}template\\Template\\main.cpp", enginePath);
                string demoHeader = string.Format("{0}template\\Classes\\DemoScene.h", enginePath);
                string demoCpp = string.Format("{0}template\\Classes\\DemoScene.cpp", enginePath);

                FileReplaceNameMove(solution, projectSolutionPath, string.Format("{0}.sln", ProjectNameText.Text));
                FileReplaceNameMove(project, projectPath, string.Format("{0}.vcxproj", ProjectNameText.Text));
                FileReplaceNameMove(projectFilter, projectPath, string.Format("{0}.vcxproj.filters", ProjectNameText.Text));

                MoveFile(mainCpp, projectPath, "main.cpp");
                MoveFile(demoHeader, projectClassPath, "DemoScene.h");
                MoveFile(demoCpp, projectClassPath, "DemoScene.cpp");

                Process.Start(projectSolutionPath);
            }
        }

        private void FileReplaceNameMove(string originPath, string movePath, string filename)
        {
            FileStream readStream = new FileStream(originPath, FileMode.Open);
            StreamReader reader = new StreamReader(readStream);

            string text = reader.ReadToEnd();
            text = text.Replace("Template", ProjectNameText.Text);

            reader.Close();
            readStream.Close();

            FileStream writeStream = new FileStream(string.Format("{0}\\{1}", movePath, filename), FileMode.Create);
            StreamWriter writer = new StreamWriter(writeStream);
            writer.WriteLine(text);
            writer.Close();
            writeStream.Close();
        }
        private void MoveFile(string originPath, string movePath, string filename)
        {
            FileInfo file = new FileInfo(originPath);
            if (file.Exists)
            {
                file.CopyTo(string.Format("{0}\\{1}", movePath, filename), true);
            }
        }

        private bool CheckEmptyBox()
        {
            if (ProjectNameText.Text.Equals(string.Empty))
            {
                MessageBox.Show("Project name is empty!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (ProjectPathText.Text.Equals(string.Empty))
            {
                MessageBox.Show("Project path is empty!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }
    }
}
