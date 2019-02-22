
type Trie struct {
    next [26]*Trie
    isword bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie {}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    self := this 
    for _, c := range word {
        idx := int(c-'a')
        if self.next[idx] == nil {
            self.next[idx] = &Trie{}
        }
        self = self.next[idx]
    }

    self.isword = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    self := this 
    for _, c := range word {
        idx := int(c-'a')
        if self.next[idx] == nil {
            return false
        }
        self = self.next[idx]
    }
    return self.isword

}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    self := this 
    for _, c := range prefix {
        idx := int(c-'a')
        if self.next[idx] == nil {
            return false
        }
        self = self.next[idx]
    }
    return true
}

