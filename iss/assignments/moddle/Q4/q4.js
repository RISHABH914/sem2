// Write answers for q4 here

// for a
db.accounts.insertOne({
    account_id: "101070",
    limit: 5000,
    products: ["brokerage", "investment stock"]
});

// for b

db.customers.insertMany([
    {
        username: "hating_it",
        name: "iiit student",
        address: "22 Gachibowli Road\nHyderabad, Telangana 500032",
        birthdate: ISODate("1993-07-10T08:15:00.000Z"),
        email: "dowhatever@iiit.ac.in",
        accounts: ["ACC420", "ACC169"]
    },
    {
        username: "no_cg",
        name: "champion",
        address: "15 North Campus\nDelhi, 110007",
        birthdate: ISODate("2006-01-20T12:45:00.000Z"),
        email: "champion@hell.iiit.ac.in",
        accounts: ["ACC3", "AC15", "AC651"]
    },
    {
        username: "toppertodropper",
        name: "hell sir",
        address: "3 FC Road\nPune, Maharashtra 411004",
        birthdate: ISODate("2002-11-05T14:30:00.000Z"),
        email: "iiit.enjoy@life.com",
        accounts: ["ACC044", "ACC955"]
    },
    {
        username: "no_money",
        name: "poor child",
        address: "45 Park Street\nKolkata, West Bengal 700016",
        birthdate: ISODate("1989-05-02T07:10:00.000Z"),
        email: "give_some_money@iiit.ac.in",
        accounts: ["ACC546", "AC459", "AC451"]
    },
    {
        username: "ug7",
        name: "cnd students",
        address: "17 Anna Salai\nChennai, Tamil Nadu 600002",
        birthdate: ISODate("1979-12-18T10:00:00.000Z"),
        email: "doing_research@7years.iiit.ac.in",
        accounts: ["ACC007", "ACC008"]
    }
]);


// for c

db.transactions.find({
    account_id: { $in: [996263, 316726, 126668,209363,328304] }
});

// for d

print("Accounts count:", db.accounts.countDocuments({}));
print("Transactions count:", db.transactions.countDocuments({}));
print("Customers count:", db.customers.countDocuments({}));


// for e

db.transactions.updateOne(
    { account_id: 228290 },
    { $set: { "transactions.1.amount": 900.50 } }
);

//i am updating one of the transactions history changing amount to 1200.50

//output for part a)
/*{
  acknowledged: true,
  insertedId: ObjectId('67ce491f5c4f3cc42fd67451')
}*/

//output for b)
/*{
  acknowledged: true,
  insertedIds: {
    '0': ObjectId('67ce496b5c4f3cc42fd67452'),
    '1': ObjectId('67ce496b5c4f3cc42fd67453'),
    '2': ObjectId('67ce496b5c4f3cc42fd67454'),
    '3': ObjectId('67ce496b5c4f3cc42fd67455'),
    '4': ObjectId('67ce496b5c4f3cc42fd67456')
  }
}*/

//output for c) only osme line from starting
/*{
  _id: ObjectId('5ca4bbc1a2dd94ee58161cb9'),
  account_id: 316726,
  transaction_count: 25,
  bucket_start_date: 1971-07-02T00:00:00.000Z,
  bucket_end_date: 2016-12-22T00:00:00.000Z,
  transactions: [
    {
      date: 2014-03-18T00:00:00.000Z,
      amount: 9094,
      transaction_code: 'sell',
      symbol: 'znga',
      price: '5.33597417328414902470967717817984521389007568359375',
      total: '48525.34913184605123070980426'
    },
    {
      date: 1998-04-07T00:00:00.000Z,
      amount: 4875,
      transaction_code: 'sell',
      symbol: 'ibm',
      price: '43.89913348329533704372806823812425136566162109375',
      total: '214008.2757310647680881743327'
    },
    {
      date: 2000-04-11T00:00:00.000Z,
      amount: 3211,
      transaction_code: 'sell',
      symbol: 'intc',
      price: '53.34781889413046229719839175231754779815673828125',
      total: '171299.8464690529144363040359'
    },*/

//output for d)
/*Accounts count:
1748
Transactions count:
1746
Customers count:
*/

//output for e) needed to change the amount to 900.5 from 1200.5 since otherwise modified count would have been 0
/*{
  acknowledged: true,
  insertedId: null,
  matchedCount: 1,
  modifiedCount: 1,
  upsertedCount: 0
}*/