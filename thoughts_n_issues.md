relational vs. non-relational - seems as if non-relational is more trendy, more suitable for commodity machines.
in most cases, non-relational does not support sql, and enables only lookups or map/reduce queries (turning kv pairs into other kv pairs than reducing)
however, it allows the db to treat all its data as {value: raw bytes}, and let the db manager (user) to write their own code to translate it back and forth, and to organize their tables logically.

structured, semi and unstructured data - 

Log-Structured Merge-Tree, B+ tree

Read / Write optimized - with transaction logs or in-place updates

Fast access vs. fast queries

Transaction - all or nothing approach for a unit of work

Rollback

Durability, Consistency, Availability, Performance

Distributed DB, Big Data - tables to big to be loaded wholly into main memory. 
Memtables

Key-value store, Columnar table, Document store

Concurrency, locks, versioning

Compaction, compression

buffer management

db as a service

Query rewrite
Query optimization

Appearantly, nested types cannot be parsed using a state machine
