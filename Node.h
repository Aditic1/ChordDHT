#ifndef Node_h
#define Node_h

#include <map>
#include "HeaderFile.h"
#include "port.h"

typedef long long int lli;

class Node{
    private:
            lli id;
            pair<pair<string,int>,lli> predecessor;
            pair<pair<string,int>,lli> successor;             //(ip,port,hashValue)
            vector<pair<pair<string,int>,lli>>fingerTable;
		    map<lli,string> dictionary;
		    vector< pair< pair<string,int> , lli >> successorList;

		    bool isInRing;
    public:
            SocketAndPort sp;

            pair<pair<string,int>,lli>findSuccessor(lli nodeId);
            pair<pair<string,int>,lli>closestPrecedingNode(lli nodeId);
            void fix_fingers();
            void checkPredecessor();
            void checkSuccessor();
            void stabilize();
            void notify(pair<pair<string,int>,lli>node);


            void printKeys();
            vector<pair<lli,string>>getAllKeysForSuccessor();
            vector<pair<lli ,string> > getKeysForPredecessor(lli nodeId);
            void updateSuccessorList();

            void setSuccessor(string ip,int port,lli hash);
            void setSuccessorList(string ip,int port,lli hash);
            void setPredecessor(string ip,int port,lli hash);
            void setFingerTable(string ip,int port,lli hash);
            void setId(lli id);
            void setStatus();
            void storeKey(lli key,string val);
            
            lli getId();
            string getValue(lli key);
            vector< pair< pair<string,int> , lli > > getFingerTable();
            pair< pair<string,int> , lli > getSuccessor();
            pair< pair<string,int> , lli > getPredecessor(); 
            vector< pair< pair<string,int> , lli > > getSuccessorList();
            bool getStatus();
};

#endif