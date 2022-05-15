## Set
Sets are a type of ordered associative containers in which each element has to be unique because the value of the element identifies it. The values are stored in a specific order. 

set<datatype> setname; // ascending order

set<datatype, greater<datatype>> setname; // descending order

### Properties:
<ol>
<li>The set stores the elements in sorted order.</li>
<li>All the elements in a set have unique values.</li>
<li>The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.</li>
<li><b>Sets follow the Binary search tree implementation.</b></li>
<li>The values in a set are unindexed.</li>
</ol>

### Some Basic Functions Associated with Set: 
<ul>
<li>begin() – Returns an iterator to the first element in the set.</li>
<li>end() – Returns an iterator to the theoretical element that follows the last element in the set.</li>
<li>size() – Returns the number of elements in the set.</li>
<li>empty() – Returns whether the set is empty.</li>
<li>insert(const g) - Adds a new element ‘g’ to the set.</li>
<li>erase(iterator position) - Removes the element at the position pointed by the iterator.</li>
<li>erase(const g) - Removes the value ‘g’ from the set.</li>
<li>clear() - Removes all the elements from the set.</li>
<li>find(const g) - Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.</li>
<li>lower_bound(const g) - Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.</li>
<li>upper_bound(const g) - Returns an iterator to the first element that will go after the element ‘g’ in the set.</li>
</ul>
