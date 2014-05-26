__author__ = 'frsilent'

from make_db_file import loadDatabase, storeDatabase

db = loadDatabase()

db['sue']['pay'] *= 1.1
db['tom']['name'] = 'Tom Tom'

storeDatabase(db)