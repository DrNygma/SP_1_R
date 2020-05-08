using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=234238

namespace SP_6
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class Calculator : Page
    {
        public Calculator()
        {
            this.InitializeComponent();
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            double a, b;
            B.IsEnabled = true;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }
            Result.Text = (a + b).ToString();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            double a, b;
            B.IsEnabled = true;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }
            Result.Text = (a - b).ToString();
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            double a, b;
            B.IsEnabled = true;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }
            Result.Text = (a * b).ToString();

        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            double a, b;

            Result.Text = "";
            B.IsEnabled = true;
            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }
            Result.Text = (b == 0 ? "Can't divide by zero" : (a / b).ToString());
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            double a;

            Result.Text = "";
            B.IsEnabled = false;

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }
            Result.Text = (Math.Sin(a)).ToString();
            B.Text = "";
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            double a;

            Result.Text = "";
            B.IsEnabled = false;

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }
            Result.Text = (Math.Cos(a)).ToString();
            B.Text = "";
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            double a;

            Result.Text = "";
            B.IsEnabled = false;

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }
            Result.Text = (Math.Tan(a)).ToString();
            B.Text = "";
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            double a;
            B.IsEnabled = false;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }
            Result.Text = (a < 0 ? "A can't be less than 0" : (Math.Sqrt(a)).ToString());
            B.Text = "";
        }

        private void Button_Click_8(object sender, RoutedEventArgs e)
        {
            double a;
            B.IsEnabled = false;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }
            Result.Text = (Math.Log(a)).ToString();
            B.Text = "";
        }

        private void Button_Click_9(object sender, RoutedEventArgs e)
        {
            double a, b;
            B.IsEnabled = true;
            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }
            Result.Text = (Math.Pow(a, b)).ToString();
        }

        private void Result_SelectionChanged(object sender, RoutedEventArgs e)
        {

        }
    }
}
