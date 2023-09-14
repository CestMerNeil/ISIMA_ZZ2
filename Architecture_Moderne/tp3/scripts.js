import http from 'k6/http';

import { sleep } from 'k6';


export default function () {

  http.get('http://front:8090/pixels');

  sleep(1);

}

