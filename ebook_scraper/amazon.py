"""
Module to purchase books from an amazon page (if free)
"""

def purchase_books(books):
    for i in books:
        print books[i]




if __name__ == '__main__':
    test_dict = {
                    u't3_1y0dh1': u'http://www.amazon.com/dp/B00EWTQI2E/ref=cm_sw_r_fa_dp_gT6.sb1P1ZRVS',
                    u't3_1xzzyx': u'http://www.amazon.com/dp/B00BXT2I20/',
                    u't3_1y083q': u'http://www.amazon.com/Omega-Rising-Force-Joshua-Dalzelle-ebook/dp/B00B795UUS/ref=zg_bs_668010011_f_55'
                 }
    purchase_books(test_dict)
