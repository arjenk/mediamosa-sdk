<?php
/**
 * @file
 * MediaMosa Library.
 */

/**
 * @file
 * The MediaMosa SDK class.
 */
class mediamosa_sdk {
  // ----------------------------------------------------------------- Settings.
  // Character length ID of asset, mediafile etc.
  const UUID_LENGTH = 24;

  // --------------------------------------------------------------- Errorcodes.
  // Error codes;
  const HTTP_OK = 200;
  const HTTP_CREATED = 201;
  const HTTP_NO_CONTENT = 204;

  const HTTP_BAD_REQUEST = 400;
  const HTTP_UNAUTHORIZED = 401;
  const HTTP_FORBIDDEN = 403;
  const HTTP_NOT_FOUND = 404;

  const HTTP_INTERNAL_SERVER_ERROR = 500;
  const HTTP_NOT_IMPLEMENTED = 501;

  // All Ok.
  const ERRORCODE_OKAY = 601;
  const ERRORCODE_TIME_RESTRICTION_START = 602;
  const ERRORCODE_TIME_RESTRICTION_END = 603;
  const ERRORCODE_FILE_NOT_FOUND = 604;
  const ERRORCODE_DIR_NOT_FOUND = 605;
  const ERRORCODE_DIR_NOT_WRITABLE = 606;
  const ERRORCODE_STREAMING_PROFILE_NOT_FOUND = 607;
  const ERRORCODE_NO_MEDIAFILE_FOUND_FOR_PROFILE_ID = 608;
  const ERRORCODE_QUERY_ERROR = 609;
  const ERRORCODE_STREAM_DOWNLOAD_NOT_ALLOWED = 610;
  const ERRORCODE_NO_METAFILE_AVAILABLE = 611;
  const ERRORCODE_JOBS_COULD_NOT_BE_STOPPED = 612;
  const ERRORCODE_REST_CALL_IS_DISABLED = 613;
  const ERRORCODE_UNABLE_TO_CREATE_SYMLINK = 614;
  const ERRORCODE_REST_UNSPECIFIED_VARIABLE = 615;
  const ERRORCODE_REST_DIFF_VALUE_GET_POST_VAR = 616;
  const ERRORCODE_REST_NOT_FOUND = 617;
  const ERRORCODE_DIR_UNABLE_TO_CREATE = 618;
  // When functions or mods are not available, like GD functions (image_*).
  const ERRORCODE_MISSING_EXTENSION = 619;
  const ERRORCODE_NO_MEDIAFILE_FOUND_FOR_TAG = 620;

  const ERRORCODE_ASSET_NOT_FOUND = 700;
  const ERRORCODE_MEDIAFILE_NOT_FOUND = 701;
  const ERRORCODE_INVALID_APP_ID = 702;
  const ERRORCODE_INVALID_USER_ID = 703;
  const ERRORCODE_UNKNOWN_ERROR_SAVING_METADATA = 704;
  const ERRORCODE_EMPTY_RESULT = 705;
  const ERRORCODE_COLLECTION_NOT_FOUND = 706;
  const ERRORCODE_COLLECTION_ASSET_RELATION_ALREADY_EXISTS = 707;
  const ERRORCODE_COLLECTION_ASSET_RELATION_NOT_FOUND = 708;
  const ERRORCODE_ASSET_NOT_EMPTY = 709;
  const ERRORCODE_COLLECTION_NOT_EMPTY = 710;
  const ERRORCODE_ASSET_SUPPLEMENT_NOT_FOUND = 711;
  const ERRORCODE_WEBSERVICE_DISABLED = 712;
  const ERRORCODE_UNKNOWN_MEDIAMOSA_VERSION = 713;
  const ERRORCODE_INVALID_ASSET_MEDIAFILE_COMBINATION = 714;
  const ERRORCODE_NO_CHANGES = 715;
  const ERRORCODE_INVALID_FAV_TYPE = 716;
  const ERRORCODE_INVALID_TIMESTAMP = 717;
  const ERRORCODE_UNEXPECTED_ERROR = 718;
  const ERRORCODE_MISSING_TIMESTAMP = 719;
  const ERRORCODE_CANT_PLAY_MEDIAFILE = 720;
  const ERRORCODE_CANT_TRANSCODE_MEDIAFILE = 721;
  const ERRORCODE_APP_DISABLED = 722;
  const ERRORCODE_MEDIAFILE_IS_NOT_ORIGINAL = 723;
  const ERRORCODE_INVALID_MEDIAFILE_RELATION = 724;
  const ERRORCODE_METADATA_MIN_OCCURRENCE_FAILURE = 725;
  const ERRORCODE_METADATA_MAX_OCCURRENCE_FAILURE = 726;

  const ERRORCODE_UNKNOWN_JOB = 800;

  // Unittest errors.
  const ERRORCODE_TEST_RUNNING = 900;

  const ERRORCODE_VALIDATE_INVALID_TYPE = 1000;
  const ERRORCODE_VALIDATE_INVALID_LENGTH_USE = 1001;
  const ERRORCODE_VALIDATE_REQUIRED_PARAMETER = 1002;
  const ERRORCODE_VALIDATE_FAILED = 1003;
  const ERRORCODE_SORT_FIELD_ERROR = 1004;
  const ERRORCODE_SORT_DIRECTION_ERROR = 1005;
  const ERRORCODE_PP_INVALID_TIME = 1006;
  const ERRORCODE_VALIDATE_INVALID_LANGUAGE = 1007;
  const ERRORCODE_INVALID_SUPPLEMENT = 1008;
  const ERRORCODE_MIX_OF_URI_AND_FILE = 1009;
  const ERRORCODE_CHANGE_URI_AND_FILE = 1010;
  const ERRORCODE_CHANGE_OWNERSHIP_MISSING_PARAMETERS = 1011;
  const ERRORCODE_INSUFFICIENT_PARAMETERS = 1012;
  const ERRORCODE_SUPPLEMENT_LIMIT_REACHED = 1013;
  const ERRORCODE_MEDIAFILE_DOWNLOAD_DISABLED = 1014;
  const ERRORCODE_UPLOAD_TARGET_IS_NOT_AN_ORIGINAL_FILE = 1015;
  const ERRORCODE_QUOTA_REACHED = 1016;
  const ERRORCODE_HOSTNAME_ALREADY_IN_GROUP = 1017;
  const ERRORCODE_HOSTNAME_NOT_FOUND = 1018;
  const ERRORCODE_GROUP_NOT_EMPTY = 1019;
  const ERRORCODE_VALIDATE_SEARCH_SYNTAX_FAILED = 1020;
  const ERRORCODE_VALIDATE_SEARCH_SYNTAX_FAILED_UNEXPECTED_END = 1021;
  const ERRORCODE_VALIDATE_SEARCH_SYNTAX_FAILED_INVALID_FIELD = 1022;
  const ERRORCODE_METADATA_DEFINITION_NOT_EMPTY = 1023;
  const ERRORCODE_INVALID_METADATA_DEFINITION = 1024;
  const ERRORCODE_HOSTNAME_TYPE_NO_MATCH_GROUP_TYPE = 1025;

  // Old 2.x naming.
  const ERRORCODE_AUT_GROUP_ALREADY_EXISTS = 1026;
  const ERRORCODE_AUT_GROUP_NOT_FOUND = 1027;
  const ERRORCODE_AUT_NAME_NOT_FOUND = 1028;

  // 3.x ++ renames.
  const ERRORCODE_ACL_GROUP_ALREADY_EXISTS = 1026;
  const ERRORCODE_ACL_GROUP_NOT_FOUND = 1027;
  const ERRORCODE_ACL_NAME_NOT_FOUND = 1028;

  const ERRORCODE_INVALID_DATA_PARAMETER = 1029;
  const ERRORCODE_FTP_BATCH_NOT_FOUND = 1030;
  const ERRORCODE_CANT_RETYPE_GROUP_MUST_BE_EMPTY = 1031;
  const ERRORCODE_CQL_EXCLUSIVE = 1032;
  const ERRORCODE_CQL_ERROR = 1033;
  const ERRORCODE_METADATA_DEFINITION_ALREADY_EXISTS = 1034;
  const ERRORCODE_ACTION_AND_REPLACE = 1035;
  const ERRORCODE_VALUE_MUST_START_WITH_ALPHABETIC_CHAR = 1036;
  const ERRORCODE_VALIDATE_INT_TO_SMALL = 1037;
  const ERRORCODE_VALIDATE_INT_TO_BIG = 1038;
  const ERRORCODE_VALIDATE_STRING_TO_SHORT = 1039;
  const ERRORCODE_VALIDATE_STRING_TO_LONG = 1040;
  const ERRORCODE_VALIDATE_VALUE_NOT_ALLOWED = 1041;
  const ERRORCODE_INTERNAL_ONLY = 1042;

  const ERRORCODE_RETRIEVING_JOBLIST = 1100;
  const ERRORCODE_RETRIEVING_JOBSTATUS = 1101;
  const ERRORCODE_WRITING_JOBSTATUS = 1102;
  const ERRORCODE_WRITING_JOBPROGRESS = 1103;
  const ERRORCODE_WRITING_UNKNOWN_JOBSTATUS = 1104;
  const ERRORCODE_RETRIEVING_TRANSCODELIST = 1105;
  const ERRORCODE_CREATING_JOB = 1106;
  const ERRORCODE_DELETING_JOB = 1107;
  const ERRORCODE_UNKNOWN_JOB_TYPE = 1108;
  const ERRORCODE_RETRIEVING_TRANSCODE_PROFILE = 1109;
  const ERRORCODE_RETRIEVING_DEFAULT_TRANSCODE_PROFILE = 1110;
  const ERRORCODE_NO_DEFAULT_TRANSCODE_PROFILE = 1111;
  const ERRORCODE_UNKNOWN_TRANSCODE_PROFILE = 1112;
  const ERRORCODE_NO_TRANSCODE_PARAMETERS = 1113;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_NOT_FOUND = 1114;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_TOO_LOW = 1115;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_TOO_HIGH = 1116;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_WRONG_VALUE = 1117;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_NOT_FLOAT = 1118;
  const ERRORCODE_JOB_TRANSCODE_PARAMETER_COMBINATION = 1119;
  const ERRORCODE_JOB_TRANSCODE_TIMEOUT = 1120;
  const ERRORCODE_CREATING_TRANSCODE_JOB = 1121;
  const ERRORCODE_JOB_NOT_FOUND = 1122;
  const ERRORCODE_JOB_ASSET_NOT_FOUND = 1123;
  const ERRORCODE_CREATING_UPLOAD_JOB = 1124;
  const ERRORCODE_CREATING_ANALYSE_JOB = 1125;
  const ERRORCODE_JOB_MEDIAFILE_NOT_FOUND = 1126;
  const ERRORCODE_JOB_USER_NOT_FOUND = 1127;
  const ERRORCODE_JOB_COULD_NOT_BE_REMOVED = 1128;
  const ERRORCODE_JOB_FRAMETIME_GREATER_THEN_DURATION = 1129;
  const ERRORCODE_RETRIEVING_ASSET = 1130;
  const ERRORCODE_TRANSCODE_PROFILE_EXISTS = 1133;
  const ERRORCODE_TRANSCODE_PROFILE_NOT_FOUND = 1134;
  const ERRORCODE_UPLOAD_ALREADY_EXISTS = 1140;
  const ERRORCODE_STILL_NOT_FOUND = 1150;
  const ERRORCODE_SERVER_STILL_NOT_FOUND = 1151;
  const ERRORCODE_SERVER_UPLOAD_NOT_FOUND = 1152;
  const ERRORCODE_STILL_NOT_IMAGE = 1153;
  const ERRORCODE_UNKNOWN_JOB_STATUS = 1154;
  const ERRORCODE_UNKNOWN_JOB_PROGRESS = 1155;
  const ERRORCODE_STILL_IS_NOT_CREATABLE = 1156;
  const ERRORCODE_CREATING_DERIVATIVE = 1157;
  const ERRORCODE_STILL_FILE_NOT_FOUND = 1158;
  const ERRORCODE_STILL_FAILED_TO_CREATE = 1159;

  const ERRORCODE_STARTING_JOB_FAILED = 1301;

  const ERRORCODE_MASTERSLAVE_DISALLOWED = 1403;
  const ERRORCODE_IMAGE_FILE_TOO_BIG = 1404;
  const ERRORCODE_MASTERSLAVE_OWN_APP = 1405;

  const ERRORCODE_INVALID_UPLOAD_TICKET = 1500;
  const ERRORCODE_CREATE_MEDIAFILE_DURING_UPLOAD = 1501;
  const ERRORCODE_CANNOT_COPY_MEDIAFILE = 1502;
  const ERRORCODE_NOT_ENOUGH_FREE_QUOTA = 1503;

  const ERRORCODE_DBUS_PROTOCOL_ERROR = 1600;
  const ERRORCODE_ACCESS_DENIED = 1601;
  const ERRORCODE_ACCESS_DENIED_INVALID_APP_ID = 1602;

  const ERRORCODE_FTP_CREDENTIAL_LENGTH = 1701;
  const ERRORCODE_FTP_UNKNOWN_USER = 1702;
  const ERRORCODE_FTP_USER_EXISTS = 1703;

  const ERRORCODE_NOT_AUTHORIZED = 1800;

  const ERRORCODE_USERMAN_INVALID_GROUP = 1900;
  const ERRORCODE_USERMAN_GROUP_NOT_EMPTY = 1901;
  const ERRORCODE_USERMAN_INVALID_USER = 1902;
  const ERRORCODE_USERMAN_GROUP_EXISTS = 1903;
  const ERRORCODE_USERMAN_USER_EXISTS = 1904;
  const ERRORCODE_IS_UNAPPROPRIATE = 1905;
  // 4.0.
  const ERRORCODE_IS_INAPPROPRIATE = 1905;

  // @deprecated use ERRORCODE_INVALID_TICKET instead.
  const ERRORCODE_INVALID_STILL_TICKET = 2000;
  const ERRORCODE_INVALID_TICKET = 2000;

  const ERRORCODE_OPENAPI_MISSING_OPEN_APP_ID = 2100;

  const ERRORCODE_INVALID_REST_CALL = 3000;

  // Storage related errorcodes.
  const ERRORCODE_STORAGE_CLASS_NOT_FOUND = 4000;
  const ERRORCODE_STORAGE_PROFILE_NOT_FOUND = 4001;
  const ERRORCODE_STORAGE_STREAMWRAPPER_NOT_FOUND = 4002;
  const ERRORCODE_STORAGE_IO_ACCESS_ERROR = 4003;
  const ERRORCODE_STORAGE_IO_ERROR = 4004;
  const ERRORCODE_STORAGE_STREAMWRAPPER_NO_REALPATH = 4005;
  const ERRORCODE_STORAGE_CHECKSUM_FAILURE = 4006;
  const ERRORCODE_STORAGE_EXTERNAL_FILE_NOT_FOUND_LOCAL = 4007;

  // ---------------------------------------------------------------- Var Types.
  // Do not make the ID value longer than 32 characters.
  //    12345678901234567890123456789012    12345678901234567890123456789012
  const TYPE_APP_ID                      = 'APP_ID'; // 1 - 9999
  const TYPE_INT                         = 'INT';
  const TYPE_UINT                        = 'UINT';
  const TYPE_FLOAT                       = 'FLOAT';
  const TYPE_SERIAL                      = 'SERIAL'; // Like autoinc. in db
  const TYPE_ALPHA                       = 'ALPHA'; // [A-Za-z]
  const TYPE_PRINTABLE                   = 'STRING_PRINTABLE';// only printable chars

  const TYPE_ALPHA_NUM                   = 'ALPHA_NUM'; // [A-Za-z0-9]
  const TYPE_ALPHA_NUM_UNDERSCORE        = 'ALPHA_NUM_UNDERSCORE'; // [A-Za-z0-9_]
  const TYPE_ALPHA_NUM_UNDERSCORE_TAG    = 'ALPHA_NUM_UNDERSCORE_TAG'; // same as ALPHA_NUM_UNDERSCORE, but does not allow the first char to be non alpha.
  const TYPE_RESPONSE_TYPE               = 'RESPONSE_TYPE';
  const TYPE_STRING                      = 'STRING';
  const TYPE_MEDIAMOSA_VERSION           = 'MEDIAMOSA_VERSION';
  const TYPE_DATETIME                    = 'DATETIME';
  const TYPE_DATETIME_UTC                = 'DATETIME_UTC'; // Is in UTC (already).
  const TYPE_DATE                        = 'DATETIME';//@todo: Extend the DATETIME check and throw errors when time values exist. REMEMBER about utc conversion.
  const TYPE_TIME                        = 'DATETIME';//@todo: Extend the DATETIME check and throw errors when date values exist. REMEMBER about utc conversion.
  const TYPE_BOOL                        = 'BOOL';
  const TYPE_MIMETYPE                    = 'MIMETYPE';
  const TYPE_XML                         = 'STRING';
  const TYPE_XML_VALIDATED               = 'XML'; // XML with syntax validation via simplexml_load_string(). Expects proper XML declaration.
  const TYPE_XML_OAI                     = 'XML_OAI'; // XML with syntax validation via DOM Document. Expects no XML declaration.
  const TYPE_EOR                         = 'EOR'; // Exclusive OR type (like 1 2 4 8, or 1|4 = 5), always UINT
  const TYPE_URI                         = 'URI'; // URI type
  const TYPE_URL                         = 'URL'; // URL type (checked with simple parse_url)
  const TYPE_URL_URI                     = 'URL'; // URL / URI type (checked with simple parse_url)
  const TYPE_ACL_GROUP_TYPE              = 'ACL_GROUP_TYPE';
  const TYPE_DELETE                      = 'DELETE';
  const TYPE_OAUTH_SIGNATURE             = 'OAUTH_SIGNATURE';
  const TYPE_OAUTH_SIGNATURE_METHOD      = 'OAUTH_SIGNATURE_METHOD';
  const TYPE_OAUTH_VERSION               = 'OAUTH_VERSION';
  const TYPE_OAUTH_TOKEN                 = 'OAUTH_TOKEN';
  const TYPE_OAUTH_VERIFIER              = 'OAUTH_VERIFIER';

  const TYPE_USER_ID                     = 'USER_ID';
  const TYPE_GROUP_ID                    = 'GROUP_ID';
  const TYPE_ASSET_ID                    = 'ASSET_ID';
  const TYPE_MEDIAFILE_ID                = 'MEDIAFILE_ID';
  const TYPE_MEDIAFILE_ID_PREFIX         = 'MEDIAFILE_ID_PREFIX';
  const TYPE_STILL_ID                    = 'MEDIAFILE_ID';
  const TYPE_COLLECTION_ID               = 'COLLECTION_ID';
  const TYPE_BATCH_ID                    = 'BATCH_ID';
  const TYPE_SUPPLEMENT_ID               = 'SUPPLEMENT_ID';
  const TYPE_TICKET_ID                   = 'TICKET_ID';
  const TYPE_TICKET_ID_PREFIX            = 'TICKET_ID_PREFIX';
  const TYPE_JOB_ID                      = 'JOB_ID';

  const TYPE_DOMAIN                      = 'DOMAIN';
  const TYPE_REALM                       = 'REALM';
  const TYPE_FILENAME                    = 'FILENAME';
  const TYPE_LANGUAGE_CODE               = 'LANGUAGE_CODE';
  const TYPE_LANGUAGE_CODE_ISO_639_3     = 'LANGUAGE_CODE_ISO_639_3';

  const TYPE_CQL_ASSET                   = 'CQL_ASSET';
  const TYPE_CQL_COLLECTION              = 'CQL_COLLECTION';
  const TYPE_CQL_JOB                     = 'CQL_JOB';

  const TYPE_ORDER_DIRECTION             = 'ORDER_DIRECTION';
  const TYPE_LIMIT                       = 'LIMIT';
  const TYPE_OPERATOR                    = 'OPERATOR'; // OR / AND.

  const TYPE_SEARCH_STRING               = 'SEARCH_STRING';
  const TYPE_SEARCH_INT                  = 'SEARCH_INT';
  const TYPE_SEARCH_DATETIME             = 'SEARCH_DATETIME';
  const TYPE_SEARCH_BOOL                 = 'SEARCH_BOOL';

  // Contains, match, exact.
  const TYPE_SEARCH_MATCH                = 'SEARCH_MATCH';

  // Job types.
  const TYPE_JOB                         = 'JOB_TYPE';
  const TYPE_COMMAND                     = 'COMMAND';
  const TYPE_JOB_STATUS                  = 'TYPE_JOB_STATUS';
  const TYPE_JOB_PROGRESS                = 'TYPE_JOB_PROGRESS';

  // Use to select what is slaved to other apps.
  const TYPE_BOOL_IS_SLAVED              = 'BOOL_IS_SLAVED';

  // Job constants.
  const JOB_STATUS = 'status';
  const JOB_STATUS_WAITING = 'WAITING';
  const JOB_STATUS_INPROGRESS = 'INPROGRESS';
  const JOB_STATUS_FINISHED = 'FINISHED';
  const JOB_STATUS_FAILED = 'FAILED';
  const JOB_STATUS_CANCELLED = 'CANCELLED';
  const JOB_STATUS_CANCELLING = 'CANCELING';// Future exp; THIS IS NOT YET ADDED TO THE ENUM IN DB 'job' table.
  const PROGRESS = 'progress';
  const JOB_TYPE = 'job_type';
  const JOB_TYPE_TRANSCODE = 'TRANSCODE';
  const JOB_TYPE_RETRANSCODE = 'RETRANSCODE';
  const JOB_TYPE_STILL = 'STILL';
  const JOB_TYPE_UPLOAD = 'UPLOAD';
  const JOB_TYPE_ANALYSE = 'ANALYSE';
  const JOB_TYPE_DELETE_MEDIAFILE = 'DELETE_MEDIAFILE';

  // ---------------------------------------------------------------- Functions.
  /**
   * Return the base URL for the SDK menu/URL.
   */
  public static function get_base_url() {
    return module_exists('mediamosa_maintenance') ? 'admin/mediamosa/config' : 'admin/config';
  }

  /**
   * Convert possible alias to real type.
   * F.e TYPE_GROUP_ID is actually a TYPE_ALPHA_NUM
   *
   * @param string $type
   */
  public static function typeAlias2Type($type) {

    switch ($type) {
      case self::TYPE_SUPPLEMENT_ID:
      case self::TYPE_USER_ID:
      case self::TYPE_GROUP_ID:
      case self::TYPE_ASSET_ID:
      case self::TYPE_MEDIAFILE_ID:
      case self::TYPE_COLLECTION_ID:
      case self::TYPE_BATCH_ID:
      case self::TYPE_JOB:
        return self::TYPE_ALPHA_NUM;

      case self::TYPE_SEARCH_BOOL:
        return self::TYPE_BOOL;

      case self::TYPE_OPERATOR:
      case self::TYPE_ORDER_DIRECTION:
        return self::TYPE_ALPHA;

      case self::TYPE_SEARCH_MATCH:
      case self::TYPE_SEARCH_STRING:
      case self::TYPE_DOMAIN:
      case self::TYPE_REALM:
      case self::TYPE_CQL_ASSET:
      case self::TYPE_CQL_COLLECTION:
      case self::TYPE_CQL_JOB:
      case self::TYPE_OAUTH_SIGNATURE:
      case self::TYPE_OAUTH_SIGNATURE_METHOD:
      case self::TYPE_OAUTH_VERSION:
      case self::TYPE_OAUTH_TOKEN:
      case self::TYPE_OAUTH_VERIFIER:
        return self::TYPE_STRING;

      case self::TYPE_SEARCH_INT:
      case self::TYPE_LIMIT:
        return self::TYPE_INT;

      case self::TYPE_SEARCH_DATETIME:
      case self::TYPE_DATETIME_UTC:
        return self::TYPE_DATETIME;
    }

    return $type;
  }

  /**
   * Check the language.
   *
   * Default metadata field dc.language is by default always ISO 639-1.
   *
   * @param string $value
   *   The value to check.
   *
   * @return bool
   *   Returns TRUE when valid, FALSE otherwise.
   */
  public static function checkLanguage($value) {
      // ISO 639-1.
      $language_codes = explode(',', 'aa,ab,ae,af,ak,am,an,ar,as,av,ay,az,ba,be,bg,bh,bi,bm,bn,bo,br,bs,ca,ce,ch,co,cr,cs,cu,cv,cy,da,de,dv,dz,ee,el,en,eo,es,et,eu,fa,ff,fi,fj,fo,fr,fy,ga,gd,gl,gn,gu,gv,ha,he,hi,ho,hr,ht,hu,hy,hz,ia,id,ie,ig,ii,ik,io,is,it,iu,ja,jv,ka,kg,ki,kj,kk,kl,km,kn,ko,kr,ks,ku,kv,kw,ky,la,lb,lg,li,ln,lo,lt,lu,lv,mg,mh,mi,mk,ml,mn,mo,mr,ms,mt,my,na,nb,nd,ne,ng,nl,nn,no,nr,nv,ny,oc,oj,om,or,os,pa,pi,pl,ps,pt,qu,rm,rn,ro,ru,rw,ry,sa,sc,sd,se,sg,sh,si,sk,sl,sm,sn,so,sq,sr,ss,st,su,sv,sw,ta,te,tg,th,ti,tk,tl,tn,to,tr,ts,tt,tw,ty,ug,uk,ur,uz,ve,vi,vo,wa,wo,xh,yi,yo,za,zh,zu');
      return in_array(drupal_strtolower($value), $language_codes);
  }

  /**
   * Parse MediaMosa version.
   *
   * major.minor[.release[.build[ optional info]]]
   *
   * @return array
   */
  public static function parse_version($version) {
    list($major, $minor, $release, $build, $info) = preg_split("/[.:-]+/", $version, 5) + array(0 => 1, 1 => 0, 2 => 0, 3 => 1, 4 => '');
    return array(
      'major' => $major,
      'minor' => $minor,
      'release' => $release,
      'build' => $build,
      'info' => $info,
    );
  }

  /**
   * Returns the database stamp as a viewable date.
   *
   * @param string $datestamp
   *   Format datetime; YYYY-MM-DD 00:00:00.
   */
  public static function datestamp2date($datestamp, $type = 'medium', $format = '', $timezone = NULL, $langcode = NULL) {
    return format_date(strtotime($datestamp), $type, $format, $timezone, $langcode);
  }

  /**
   * Returns an encoded metadata tag that can be used to update asset metadata
   * or in CQL strings.
   *
   * @param mixed $vocabulary
   *   Name of the taxonomy vocabulary.
   *
   *   Either as string or as an array. Array is only needed when building a
   *   search string for CQL.
   *   - 'pattern' with a pattern that should not be urlencoded.
   *   - 'vars' with an associative array of values that should be urlencoded.
   *      and need to be replaced in the pattern.
   *
   *   Example;
   *     array(
   *       'pattern' => '{term}*',
   *       'vars' => array('{term}' => 'foo')
   *     );
   *     Results into '0.foo%20*'
   *
   * @param array $term
   *   - 'pattern' with a pattern that should not be urlencoded.
   *   - 'vars' with an associative array of values that should be urlencoded
   *      and need to be replaced in the pattern.
   *   Terms for each level of the hierarchical taxonomy tree based on the rules
   *   as the vocabulary name.
   *
   *   Example;
   *     array(
   *       array('pattern' => '*'),
   *       array('pattern' => '{term}*', 'vars' => array('{term}' => 'foo ')),
   *       'bar'
   *     );
   */
  //     Results into '1.*/2.foo%20*/3.bar/'
  /*
   * @return string
   *   The encoded string to use for CQL or storage for metadata.
  */
  public static function metadata_encode_tag($vocabulary, array $term) {
    if (is_array($vocabulary)) {
      if (empty($vocabulary['vars'])) {
        $vocabulary = $vocabulary['pattern'];
      }
      else {
        foreach ($vocabulary['vars'] as &$text) {
          $text = urlencode($text);
        }
        $vocabulary = strtr($vocabulary['pattern'], $vocabulary['vars']);
      }
    }
    else {
      $vocabulary = urlencode($vocabulary);
    }

    $tag = '0.' . $vocabulary;
    $scope = 1;
    foreach ($term as $name) {
      if (is_array($name)) {
        if (empty($name['vars'])) {
          $name = $name['pattern'];
        }
        else {
          foreach ($name['vars'] as &$text) {
            $text = urlencode($text);
          }
          $name = strtr($name['pattern'], $name['vars']);
        }
      }
      else {
        $name = urlencode($name);
      }

      $tag .= '/' . $scope++ . '.' . $name;
    }

    return $tag . '/';
  }

  /**
   * Escape values for CQL.
   *
   * @param string $value
   *   The value to escape.
   *
   * @return string
   *   The escaped string.
   */
  public static function escape_cql($value) {
    return addslashes($value);
  }
}
