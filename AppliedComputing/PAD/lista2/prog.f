program meuprog
integer , parameter :: m=4000
integer :: i,j
double precision, allocatable :: a(:,:),b(:,:)
double precision s,soma,t1,t2,mysecond

allocate(a(m,m))
allocate(b(m,m))

s=1.1
soma=0
do i=1,m
        do j=1,m
                if (((j/2)*2).eq.j) then 
                        a(i,j)=1
                else 
                        a(i,j) = -1
                endif
                b(i,j)=0
        enddo
enddo

t1=mysecond()
do i=1,m
        do j=1,m
                b(i,j) = s * a(i,j)
                soma = soma + b(i,j)
        enddo
enddo
t2=mysecond()

print *,"soma=",soma," Tempo=",t2-t1
stop
end