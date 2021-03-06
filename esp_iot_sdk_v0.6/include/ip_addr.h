#ifndef __IP_ADDR_H__
#define __IP_ADDR_H__

struct ip_addr {
    uint32 addr;
};

struct ip_info {
    struct ip_addr ip;
    struct ip_addr netmask;
    struct ip_addr gw;
};

/**
 * Determine if two address are on the same network.
 *
 * @arg addr1 IP address 1
 * @arg addr2 IP address 2
 * @arg mask network identifier mask
 * @return !0 if the network identifiers of both address match
 */
#define ip_addr_netcmp(addr1, addr2, mask) (((addr1)->addr & \
        (mask)->addr) == \
        ((addr2)->addr & \
         (mask)->addr))

#define ip4_addr1(ipaddr) (((uint8*)(ipaddr))[0])
#define ip4_addr2(ipaddr) (((uint8*)(ipaddr))[1])
#define ip4_addr3(ipaddr) (((uint8*)(ipaddr))[2])
#define ip4_addr4(ipaddr) (((uint8*)(ipaddr))[3])

#define ip4_addr1_16(ipaddr) ((uint16)ip4_addr1(ipaddr))
#define ip4_addr2_16(ipaddr) ((uint16)ip4_addr2(ipaddr))
#define ip4_addr3_16(ipaddr) ((uint16)ip4_addr3(ipaddr))
#define ip4_addr4_16(ipaddr) ((uint16)ip4_addr4(ipaddr))

uint32 ipaddr_addr(const char *cp);

#define IP2STR(ipaddr) ip4_addr1_16(ipaddr), \
    ip4_addr2_16(ipaddr), \
    ip4_addr3_16(ipaddr), \
    ip4_addr4_16(ipaddr)

#define IPSTR "%d.%d.%d.%d"

#endif /* __IP_ADDR_H__ */
