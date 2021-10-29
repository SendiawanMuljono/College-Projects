using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Handler;
using PSD_Project.Report;

namespace PSD_Project.Controller
{
    public class TransactionController
    {
        public static string validationTransactionPreorder(int quantity, int floID, int memID, DateTime trDate)
        {
            string msg = "";
            if(quantity < 1 || quantity > 100)
            {
                msg += "Quantity must be between 1 to 100 inclusively! ";
            }

            if (msg.Equals(""))
            {
                TransactionHandler.InsertTransactionPreorder(quantity, floID, memID, trDate);
            }
            return msg;
        }
        public static TrHistoryReport trHistoryReport()
        {
            TrHistoryReport trHistory = new TrHistoryReport();
            trHistory.SetDataSource(TransactionHandler.GetDataset());
            return trHistory;
        }
    }

}