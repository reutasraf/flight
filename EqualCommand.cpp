#include "EqualCommand.h"

/**
 * the Equal command-update the vars according to the user lines
 * @param vector1 the vector of the data
 * @param map1 the map of the value of the vars
 * @param index-the index of the current data we need
 * @return
 */
int EqualCommand::doCommand(vector<vector<string>> vector1, map<string, double> *map1, int index) {

    //update the var in our map to according to the user change

     string valueExpr="";
     //save the value we need to update
     for (int i=2;i<vector1[index].size();i++){
         valueExpr=valueExpr+vector1[index][i]+" ";
     }
     double val=this->dijkstra1->toVl(valueExpr);


    pthread_mutex_lock(this->mut);
    if (map1->count(vector1[index][0])) {
        (*map1)[vector1[index][0]] = val;
    } else  {
        //cant be
    }
    pthread_mutex_unlock(this->mut);
    //check if it bind

    if(this->server1->getPath(vector1[index][0])!= ""){
            string s = "set ";
        s = s+this->server1->getPath(vector1[index][0]);
                                            //s = s+" "+vector1[index][0]+"\r\n";
        s = s+" "+to_string(val)+"\r\n";
        this->dataClient->setData(s);
    }

    return 3;
}
