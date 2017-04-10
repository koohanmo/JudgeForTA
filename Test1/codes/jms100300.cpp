#include<cstdio>
#include<vector>
#include<algorithm>

int main(void)
{
        int T; scanf("%d", &T);

        long long A, B, N;
        long long n_A, n_B;
        long long primes[1000000];
        int primes_cnt;

        for(int index = 1; index <= T; index++)
        {
                scanf("%lld %lld %lld", &A, &B, &N);
                primes_cnt = -1;

                for (long long i = 2; i * i < N; i++)
                {
                        if (N % i == 0)
                        {
                                primes[++primes_cnt] = i;
                                while(N % i == 0)
                                        N /= i;
                        }
                }
                if (N > 1)
                {
                        primes[++primes_cnt] = N;
                }

                long long div, neg = -1;
                n_A = --A, n_B = B;

                for (int i = 0; i <= primes_cnt; i++, neg = -neg)
                {
                        std::vector<bool> v(primes_cnt + 1);
                        std::fill(v.begin(), v.begin() + i + 1, true);

                        do
                        {
                                div = 1;
                                for (int j = 0; j <= primes_cnt; j++)
                                {
                                        if (v[j])
                                                div *= primes[j];
                                }
                                n_A += neg * (A / div);
                                n_B += neg * (B / div);

                        } while (std::prev_permutation(v.begin(), v.end()));


                }

                printf("Case #%d: %lld\n", index, n_B - n_A);
        }
}
