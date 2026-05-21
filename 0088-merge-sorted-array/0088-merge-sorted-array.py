class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i=0
        j=0
        result=[]
        while i<=m-1 and j<=n-1:
            if nums1[i] < nums2[j]:
                result.append(nums1[i])
                i+=1
            else:
                result.append(nums2[j])
                j+=1
        
        while j<=n-1:
            result.append(nums2[j])
            j+=1

        while i<=m-1:
            result.append(nums1[i])
            i+=1
        
        nums1[:] = result
        