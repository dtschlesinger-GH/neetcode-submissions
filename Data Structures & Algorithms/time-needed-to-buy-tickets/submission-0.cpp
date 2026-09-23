class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<bool, int>> ticketQueue;
        int timeCounter = 0;
        
        for (int i = 0; i < tickets.size(); i++) 
        {
            if (i == k) 
            {
                ticketQueue.push({true, tickets[i]});
                continue;
            }
            ticketQueue.push({false, tickets[i]});
        }

        while (!ticketQueue.empty()) 
        {
            timeCounter++;
            pair<bool, int> head = ticketQueue.front();
            ticketQueue.pop();
            head.second -= 1;
            if (head.second == 0) 
            {
                if (head.first) 
                {
                    return timeCounter;
                }
                continue;
            }
            ticketQueue.push(head);
        }

        return 1;
    }
};