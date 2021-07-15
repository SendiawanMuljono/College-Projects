using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Dataset;
using PSD_Project.Factory;
using PSD_Project.Model;
using PSD_Project.Repository;

namespace PSD_Project.Handler
{
    public class TransactionHandler
    {
        public static void InsertTransactionPreorder(int quantity, int floID, int memID, DateTime trDate)
        {
            TrHeader lastTr = TransactionRepository.getLastTrHeader();
            if (lastTr == null || lastTr.MemberID != memID)
            {
                TrHeader trHeader = TransactionFactory.CreateTrHeader(memID, trDate);
                TransactionRepository.InsertTrHeader(trHeader);
                lastTr = TransactionRepository.getLastTrHeader();
            }
            TrDetail trDetail = TransactionFactory.CreateTrDetail(lastTr.TransactionID, quantity, floID);
            TransactionRepository.InsertTrDetail(trDetail);
        }

        public static TrHistoryDataset GetDataset()
        {
            int memID = int.Parse(((MsMember)HttpContext.Current.Session["member"]).MemberID.ToString());
            return TransactionFactory.CreateData(MemberRepository.getMemberById(memID));
        }
    }
}