__author__ = 'frsilent'

from make_db_file import loadDatabase

db = loadDatabase()
for key in db:
    print(key, '=>\n ', db[key])
print(db['sue']['name'])