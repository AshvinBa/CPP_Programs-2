
// deque<int>maxi(k);
//     deque<int>mini(k);

//     for(int i=0;i<k;i++)
//     {
//         while( !maxi.empty() && nums[maxi.back()] <= nums[i] )
//         maxi.pop_back();

//         while( !mini.empty() && nums[mini.back()] >= nums[i] )
//         mini.pop_back();

//         maxi.push_back(i);
//         mini.push_back(i);        
//     }
//     int ans=0;
//     for(int i=k;i<n;i++)
//     {
//         ans+=nums[maxi.front()]+nums[mini.front()];

//         while(!maxi.empty() && i-maxi.front()>=k)
//         {
//             maxi.pop_front();
//         }
//         while(!mini.empty() && i-mini.front()>=k)
//         {
//             mini.pop_front();
//         }

//         while(!maxi.empty() && nums[maxi.back()] <= nums[i])
//         maxi.pop_back();

//         while(!mini.empty() && nums[mini.back()] >= nums[i])
//         mini.pop_back();

//         maxi.push_back(i);
//         mini.push_back(i);
//     }
//     ans+=nums[maxi.front()]+nums[mini.front()];

//     return ans;
