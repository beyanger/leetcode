
func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}


func minDistance(word1 string, word2 string) int {
    s1, s2 := len(word1), len(word2)

    if s1 == 0 || s2 == 0 {
        return s1 + s2
    }

    dp = make([][]int, s1+1)
    for i := 0; i <= s1; i++ {
        dp[i] = make([]int, s2+1)
    }

    for i := 0; i <= s1; i++ {
        dp[i][0] = i
    }
    for i := 0; i <= s2; i++ {
        dp[0][i] = i
    }

    for i := 0; i < s1; i++ {
        for j := 0; j < s2; j++ {
            if word1[i] == word2[j] {
                dp[i+1][j+1] = dp[i][j]
            } else {
                dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1
            }
        }
    }
    return dp[s1][s2]
}
