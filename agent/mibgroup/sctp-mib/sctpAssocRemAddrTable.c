/*
 * Note: this file originally auto-generated by mib2c using
 *  $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/agent/table_container.h>
#include "sctpAssocRemAddrTable.h"

/*
 * content of the sctpAssocRemAddrTable 
 */
static netsnmp_container *sctpAssocRemAddrTable_container;

/** Initializes the sctpAssocRemAddrTable module */
void
init_sctpAssocRemAddrTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_sctpAssocRemAddrTable();
}

void
shutdown_sctpAssocRemAddrTable(void)
{
    sctpAssocRemAddrTable_container_clear(sctpAssocRemAddrTable_container);
}

/** Initialize the sctpAssocRemAddrTable table by defining its contents and how it's structured */
void
initialize_table_sctpAssocRemAddrTable(void)
{
    static oid      sctpAssocRemAddrTable_oid[] =
        { 1, 3, 6, 1, 2, 1, 104, 1, 5 };
    size_t          sctpAssocRemAddrTable_oid_len =
        OID_LENGTH(sctpAssocRemAddrTable_oid);
    netsnmp_handler_registration *reg = NULL;
    netsnmp_mib_handler *handler = NULL;
    netsnmp_container *container = NULL;
    netsnmp_table_registration_info *table_info = NULL;

    reg =
        netsnmp_create_handler_registration("sctpAssocRemAddrTable",
                                            sctpAssocRemAddrTable_handler,
                                            sctpAssocRemAddrTable_oid,
                                            sctpAssocRemAddrTable_oid_len,
                                            HANDLER_CAN_RONLY);
    if (NULL == reg) {
        snmp_log(LOG_ERR,
                 "error creating handler registration for sctpAssocRemAddrTable\n");
        goto bail;
    }

    container =
        netsnmp_container_find("sctpAssocRemAddrTable:table_container");
    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "error creating container for sctpAssocRemAddrTable\n");
        goto bail;
    }
    sctpAssocRemAddrTable_container = container;

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    if (NULL == table_info) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpAssocRemAddrTable\n");
        goto bail;
    }
    netsnmp_table_helper_add_indexes(table_info, ASN_UNSIGNED,  /* index: sctpAssocId */
                                     ASN_INTEGER,       /* index: sctpAssocRemAddrType */
                                     ASN_OCTET_STR,     /* index: sctpAssocRemAddr */
                                     0);
    table_info->min_column = COLUMN_SCTPASSOCREMADDRACTIVE;
    table_info->max_column = COLUMN_SCTPASSOCREMADDRSTARTTIME;

    /*************************************************
     *
     * inject container_table helper
     */
    handler = netsnmp_container_table_handler_get(table_info, container,
                                                  TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    if (NULL == handler) {
        snmp_log(LOG_ERR,
                 "error allocating table registration for sctpAssocRemAddrTable\n");
        goto bail;
    }
    if (SNMPERR_SUCCESS != netsnmp_inject_handler(reg, handler)) {
        snmp_log(LOG_ERR,
                 "error injecting container_table handler for sctpAssocRemAddrTable\n");
        goto bail;
    }
    handler = NULL;             /* reg has it, will reuse below */

    /*
     * register the table
     */
    if (SNMPERR_SUCCESS != netsnmp_register_table(reg, table_info)) {
        snmp_log(LOG_ERR,
                 "error registering table handler for sctpAssocRemAddrTable\n");
        reg = NULL; /* it was freed inside netsnmp_register_table */
        goto bail;
    }

    /*
     * Initialise the contents of the table here
     */


    return;                     /* ok */

    /*
     * Some error occurred during registration. Clean up and bail.
     */
  bail:                        /* not ok */

    if (handler)
        netsnmp_handler_free(handler);

    if (table_info)
        netsnmp_table_registration_info_free(table_info);

    if (container)
        CONTAINER_FREE(container);

    if (reg)
        netsnmp_handler_registration_free(reg);
}


/** handles requests for the sctpAssocRemAddrTable table */
int
sctpAssocRemAddrTable_handler(netsnmp_mib_handler *handler,
                              netsnmp_handler_registration *reginfo,
                              netsnmp_agent_request_info *reqinfo,
                              netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    sctpAssocRemAddrTable_entry *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            if (request->processed)
                continue;
            table_entry = (sctpAssocRemAddrTable_entry *)
                netsnmp_container_table_extract_context(request);
            table_info = netsnmp_extract_table_info(request);
            if ((NULL == table_entry) || (NULL == table_info)) {
                snmp_log(LOG_ERR,
                         "could not extract table entry or info for sctpAssocRemAddrTable\n");
                snmp_set_var_typed_value(request->requestvb,
                                         SNMP_ERR_GENERR, NULL, 0);
                continue;
            }

            switch (table_info->colnum) {
            case COLUMN_SCTPASSOCREMADDRACTIVE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->sctpAssocRemAddrActive);
                break;
            case COLUMN_SCTPASSOCREMADDRHBACTIVE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->sctpAssocRemAddrHBActive);
                break;
            case COLUMN_SCTPASSOCREMADDRRTO:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb,
                                           ASN_UNSIGNED,
                                           table_entry->sctpAssocRemAddrRTO);
                break;
            case COLUMN_SCTPASSOCREMADDRMAXPATHRTX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb,
                                           ASN_UNSIGNED,
                                           table_entry->sctpAssocRemAddrMaxPathRtx);
                break;
            case COLUMN_SCTPASSOCREMADDRRTX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_COUNTER,
                                           table_entry->sctpAssocRemAddrRtx);
                break;
            case COLUMN_SCTPASSOCREMADDRSTARTTIME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb,
                                           ASN_TIMETICKS,
                                           table_entry->sctpAssocRemAddrStartTime);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

    }
    return SNMP_ERR_NOERROR;
}

sctpAssocRemAddrTable_entry *
sctpAssocRemAddrTable_entry_create(void)
{
    sctpAssocRemAddrTable_entry *entry =
        SNMP_MALLOC_TYPEDEF(sctpAssocRemAddrTable_entry);
    if (entry != NULL) {
        entry->oid_index.len = SCTP_ASSOC_REM_ADDR_TABLE_INDEX_SIZE;
        entry->oid_index.oids = entry->oid_tmp;
    }

    return entry;
}

int
sctpAssocRemAddrTable_entry_update_index(sctpAssocRemAddrTable_entry *
                                         entry)
{
    int             err = 0;

    netsnmp_variable_list var_sctpAssocId;
    netsnmp_variable_list var_sctpAssocRemAddrType;
    netsnmp_variable_list var_sctpAssocRemAddr;

    /*
     * prepare the values to be converted 
     */
    memset(&var_sctpAssocId, 0, sizeof(var_sctpAssocId));
    var_sctpAssocId.type = ASN_UNSIGNED;
    memset(&var_sctpAssocRemAddrType, 0, sizeof(var_sctpAssocRemAddrType));
    var_sctpAssocRemAddrType.type = ASN_INTEGER;
    memset(&var_sctpAssocRemAddr, 0, sizeof(var_sctpAssocRemAddr));
    var_sctpAssocRemAddr.type = ASN_OCTET_STR;

    var_sctpAssocId.next_variable = &var_sctpAssocRemAddrType;
    var_sctpAssocRemAddrType.next_variable = &var_sctpAssocRemAddr;
    var_sctpAssocRemAddr.next_variable = NULL;

    snmp_set_var_value(&var_sctpAssocId, (u_char *) & entry->sctpAssocId,
                       sizeof(entry->sctpAssocId));
    snmp_set_var_value(&var_sctpAssocRemAddrType,
                       (u_char *) & entry->sctpAssocRemAddrType,
                       sizeof(entry->sctpAssocRemAddrType));
    snmp_set_var_value(&var_sctpAssocRemAddr,
                       (u_char *) & entry->sctpAssocRemAddr,
                       entry->sctpAssocRemAddr_len *
                       sizeof(entry->sctpAssocRemAddr[0]));

    /*
     * convert it 
     */
    err =
        build_oid_noalloc(entry->oid_index.oids, entry->oid_index.len,
                          &entry->oid_index.len, NULL, 0,
                          &var_sctpAssocId);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * release any memory allocated during the conversion 
     */
    snmp_reset_var_buffers(&var_sctpAssocId);

    return err;

}

void
sctpAssocRemAddrTable_entry_copy(sctpAssocRemAddrTable_entry * from,
                                 sctpAssocRemAddrTable_entry * to)
{
    memcpy(to, from, sizeof(sctpAssocRemAddrTable_entry));
    to->oid_index.oids = to->oid_tmp;
}

void
sctpAssocRemAddrTable_entry_free(sctpAssocRemAddrTable_entry * entry)
{
    if (entry != NULL)
        SNMP_FREE(entry);
}

netsnmp_container *
sctpAssocRemAddrTable_get_container(void)
{
    return sctpAssocRemAddrTable_container;
}


static void
sctpAssocRemAddrTable_entry_clear(void *what, void *magic)
{
    sctpAssocRemAddrTable_entry_free(what);
}

void
sctpAssocRemAddrTable_container_clear(netsnmp_container *container)
{
    CONTAINER_CLEAR(container, sctpAssocRemAddrTable_entry_clear, NULL);
}
