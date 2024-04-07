#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <netinet/ether.h>
#include <arpa/inet.h>

/* IP Header */
struct ipheader {
  unsigned char      iph_ihl:4,
                     iph_ver:4;
  unsigned char      iph_tos;
  unsigned short int iph_len;
  unsigned short int iph_ident;
  unsigned short int iph_flag:3,
                     iph_offset:13;
  unsigned char      iph_ttl;
  unsigned char      iph_protocol;
  unsigned short int iph_chksum;
  struct  in_addr    iph_sourceip;
  struct  in_addr    iph_destip;
};
/* TCP Header */
struct tcpheader {
    u_short tcp_sport;
    u_short tcp_dport;
    u_int   tcp_seq;
    u_int   tcp_ack;
    u_char  tcp_offx2;
    u_char  tcp_flags;
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80
#define TH_FLAGS        (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
    u_short tcp_win;
    u_short tcp_sum;
    u_short tcp_urp;
};
/* Ethernet header */
struct ethheader {
    u_char  ether_dhost[6];
    u_char  ether_shost[6];
    u_short ether_type;
};

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    struct ethheader *eth = (struct ethheader *)packet;
    struct ipheader *ip = (struct ipheader *)(packet + sizeof(struct ethheader));
    struct tcpheader *tcp = (struct tcpheader *)(packet + sizeof(struct ethheader) + ip -> iph_ihl * 4);
    
    // Ethernet
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth -> ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth -> ether_dhost));

    // IP
    printf("Source IP: %s\n", inet_ntoa(ip -> iph_sourceip));
    printf("Destination IP: %s\n", inet_ntoa(ip -> iph_destip));

    // TCP
    printf("Source Port: %d\n", ntohs(tcp -> tcp_sport));
    printf("Destination Port: %d\n", ntohs(tcp -> tcp_dport));

    printf("\n");
}

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];

    handle = pcap_open_live("eth00", BUFSIZ, 1, 1000, errbuf);
    pcap_loop(handle, 0, got_packet, NULL);
    pcap_close(handle);

    return 0;
}