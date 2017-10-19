namespace ProjectCreator
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.ProjectNameText = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.ProjectPathText = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ProjectPathButton = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ProjectNameText
            // 
            this.ProjectNameText.Location = new System.Drawing.Point(12, 24);
            this.ProjectNameText.Name = "ProjectNameText";
            this.ProjectNameText.Size = new System.Drawing.Size(239, 21);
            this.ProjectNameText.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 12);
            this.label2.TabIndex = 4;
            this.label2.Text = "Project Name";
            // 
            // ProjectPathText
            // 
            this.ProjectPathText.Location = new System.Drawing.Point(12, 72);
            this.ProjectPathText.Name = "ProjectPathText";
            this.ProjectPathText.Size = new System.Drawing.Size(239, 21);
            this.ProjectPathText.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(10, 57);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(73, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "Project Path";
            // 
            // ProjectPathButton
            // 
            this.ProjectPathButton.Location = new System.Drawing.Point(257, 72);
            this.ProjectPathButton.Name = "ProjectPathButton";
            this.ProjectPathButton.Size = new System.Drawing.Size(61, 21);
            this.ProjectPathButton.TabIndex = 7;
            this.ProjectPathButton.Text = "...";
            this.ProjectPathButton.UseVisualStyleBackColor = true;
            this.ProjectPathButton.Click += new System.EventHandler(this.ProjectPathButton_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 101);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(306, 29);
            this.button2.TabIndex = 8;
            this.button2.Text = "Create Project";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(329, 139);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.ProjectPathButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ProjectPathText);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.ProjectNameText);
            this.MaximumSize = new System.Drawing.Size(345, 178);
            this.MinimumSize = new System.Drawing.Size(345, 178);
            this.Name = "Form1";
            this.Text = "CotEngine Project Creator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox ProjectNameText;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ProjectPathText;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button ProjectPathButton;
        private System.Windows.Forms.Button button2;
    }
}

