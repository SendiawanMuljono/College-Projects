using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using PSD_Project.Dataset;
using PSD_Project.Model;

namespace PSD_Project.Factory
{
    public class TransactionFactory
    {
        public static TrHeader CreateTrHeader(int memID, DateTime trDate)
        {
            TrHeader trHeader = new TrHeader();
            trHeader.MemberID = memID;
            trHeader.TransactionDate = trDate;

            return trHeader;
        }


        public static TrDetail CreateTrDetail(int trID, int quantity, int floID)
        {
            TrDetail trDetail = new TrDetail();
            trDetail.TransactionID = trID;
            trDetail.Quantity = quantity;
            trDetail.FlowerID = floID;

            return trDetail;
        }

        public static TrHistoryDataset CreateData(MsMember member)
        {
            TrHistoryDataset ds = new TrHistoryDataset();
            var trHeader = ds.TrHeader;
            var memHeader = ds.MsMember;
            var trDetail = ds.TrDetail;
            var floDetail = ds.MsFlower;

            var memRow = memHeader.NewRow();
            memRow["MemberID"] = member.MemberID;
            memRow["MemberName"] = member.MemberName;
            memHeader.Rows.Add(memRow);

            foreach(TrHeader tr in member.TrHeaders)
            {
                long a = 0;
                var rowTrHeader = trHeader.NewRow();
                rowTrHeader["TransactionID"] = tr.TransactionID;
                rowTrHeader["MemberID"] = tr.MemberID;
                rowTrHeader["TransactionDate"] = tr.TransactionDate;
                trHeader.Rows.Add(rowTrHeader);
                
                foreach(TrDetail detail in tr.TrDetails)
                {
                    var rowTrDetail = trDetail.NewRow();
                    rowTrDetail["TransactionID"] = detail.TransactionID;
                    rowTrDetail["FlowerID"] = detail.FlowerID;
                    rowTrDetail["Quantity"] = detail.Quantity;
                    rowTrDetail["subtotal"] = detail.Quantity * detail.MsFlower.FlowerPrice;
                    a += detail.Quantity * detail.MsFlower.FlowerPrice;
                    rowTrDetail["grandtotal"] = a;
                    trDetail.Rows.Add(rowTrDetail);

                    var rowFlower = floDetail.NewRow();
                    rowFlower["FlowerID"] = detail.MsFlower.FlowerID;
                    rowFlower["FlowerName"] = detail.MsFlower.FlowerName;
                    rowFlower["FlowerPrice"] = detail.MsFlower.FlowerPrice;
                    floDetail.Rows.Add(rowFlower);
                }
                //var rowGrandTotal = trDetail.NewRow();
                //rowGrandTotal["grandtotal"] = a;
                //trDetail.Rows.Add(rowGrandTotal);
            }

            return ds;
        }
    }
}