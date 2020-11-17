using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Text_Editor_Dark
{
    public partial class Form1 : Form
    {
        static string filename;
        static string sfilename;
        public Form1()
        {
            InitializeComponent();
        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            filename = null;
            sfilename = null;
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog od = new OpenFileDialog();
            od.Filter = "Rich Text Files | *.rtf";
            od.DefaultExt = "rtf";
            DialogResult result = od.ShowDialog();
            if (result != DialogResult.Cancel)
            {
                filename = od.FileName;
                richTextBox1.LoadFile(filename);
                this.Text = sfilename = od.SafeFileName;
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (filename != null)
            {
                richTextBox1.SaveFile(filename);
                this.Text = sfilename;
            }
            else
            {
                SaveFileDialog sd = new SaveFileDialog();
                sd.Filter = "Rich Text Files | *.rtf";
                sd.DefaultExt = "rtf";
                DialogResult result = sd.ShowDialog();
                if(result != DialogResult.Cancel  )
                {
                    filename = sd.FileName;
                    richTextBox1.SaveFile(filename);
                    this.Text = sfilename = Path.GetFileName(filename);
                }

            }
        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog sd = new SaveFileDialog();
            sd.Filter = "Rich Text Files | *.rtf";
            sd.DefaultExt = "rtf";
            DialogResult result = sd.ShowDialog();
            if (result != DialogResult.Cancel)
            {
                filename = sd.FileName;
                richTextBox1.SaveFile(filename);
              this.Text =  sfilename = Path.GetFileName(filename);
            }
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            if (sfilename != null)
            {
                this.Text = sfilename + "*";

            }
            else
            {

                this.Text = "New File*";
            }
        }
    }
}
