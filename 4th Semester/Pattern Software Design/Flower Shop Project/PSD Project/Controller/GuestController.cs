using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using PSD_Project.Handler;
using PSD_Project.Model;

namespace PSD_Project.Controller
{
    public class GuestController
    {
        public static string login(string email, string password, bool isChecked)
        {
            string msg = "";

            if (email.Equals(""))
            {
                msg += "Email must be filled! ";
            }
            if (password.Equals(""))
            {
                msg += "Password must be filled! ";
            }
            if (!email.Equals("") && !password.Equals(""))
            {
                MsEmployee msEmployee = GuestHandler.empLogin(email, password);
                MsMember msMember = GuestHandler.memLogin(email, password);
                if (msEmployee == null && msMember == null)
                {
                    msg += "Not found! ";
                }
                else
                {
                    if (isChecked == true)
                    {
                        HttpCookie loginCookie = new HttpCookie("login");
                        if(msEmployee != null)
                        {
                            loginCookie.Values["email"] = msEmployee.EmployeeEmail.ToString();
                            loginCookie.Values["password"] = msEmployee.EmployeePassword.ToString();
                            loginCookie.Expires = DateTime.Now.AddDays(1);
                            HttpContext.Current.Response.Cookies.Add(loginCookie);
                        }
                        else
                        {
                            //member
                            loginCookie.Values["email"] = msMember.MemberEmail.ToString();
                            loginCookie.Values["password"] = msMember.MemberPassword.ToString();
                            loginCookie.Expires = DateTime.Now.AddDays(1);
                            HttpContext.Current.Response.Cookies.Add(loginCookie);
                        }
                    }
                    if(msEmployee != null)
                    {
                        if (msEmployee.EmployeeEmail.Equals("admin@neinteen.com"))
                        {
                            HttpContext.Current.Session.Add("admin", msEmployee);
                        }
                        else
                        {
                            HttpContext.Current.Session.Add("employee", msEmployee);
                        }
                    }
                    else
                    {
                        HttpContext.Current.Session.Add("member", msMember);
                    }
                }
            }

            return msg;
        }

        public static string GetCaptcha()
        {
            Random rand = new Random();
            StringBuilder stringBuilder = new StringBuilder();
            char text;
            string intRand = rand.Next(100, 999).ToString();
            for (int i = 0; i < 3; i++)
            {
                double flt = rand.NextDouble();
                int shift = Convert.ToInt32(Math.Floor(25 * flt));
                text = Convert.ToChar(shift + 65);
                stringBuilder.Append(text);
            }
            var captcha = (stringBuilder.ToString() + intRand);

            return captcha;
        }

        public static string forgotPass(string Email, string newPassword, string txtCaptcha, string Captcha)
        {
            string msg = "";
            if (Email.Equals(""))
            {
                msg += "Email must be filled! ";
            }
            if (txtCaptcha.Equals(""))
            {
                msg += "Captcha must be filled! ";
            }
            if (newPassword.Equals(""))
            {
                msg += "New Password must be filled! ";
            }
            if(!Email.Equals("") && !txtCaptcha.Equals("") && !newPassword.Equals(""))
            {
                var cek = GuestHandler.get_obj_by_email(Email, newPassword);
                if (!cek)
                {
                    msg += "Email not found! ";
                }
                if (!txtCaptcha.Equals(Captcha))
                {
                    msg += "Captcha must be same as shown! ";
                }
                if (!newPassword.Equals(Captcha))
                {
                    msg += "New Password must be the same as captcha! ";
                }

                if (msg.Equals(""))
                {
                    msg = "Success";
                }
            }
            return msg;
        }
    }
}