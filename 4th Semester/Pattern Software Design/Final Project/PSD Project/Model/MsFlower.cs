//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace PSD_Project.Model
{
    using System;
    using System.Collections.Generic;
    
    public partial class MsFlower
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public MsFlower()
        {
            this.TrDetails = new HashSet<TrDetail>();
        }
    
        public int FlowerID { get; set; }
        public string FlowerName { get; set; }
        public Nullable<int> FlowerTypeID { get; set; }
        public string FlowerDescription { get; set; }
        public long FlowerPrice { get; set; }
        public string FlowerImage { get; set; }
    
        public virtual MsFlowerType MsFlowerType { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<TrDetail> TrDetails { get; set; }
    }
}