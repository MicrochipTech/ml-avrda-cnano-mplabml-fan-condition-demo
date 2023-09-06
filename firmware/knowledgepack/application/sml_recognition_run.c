#include "kb.h"
#include "sml_output.h"
#include "sml_recognition_run.h"

#ifdef SML_USE_TEST_DATA
#include "testdata.h"
int32_t td_index = 0;
#endif //SML_USE_TEST_DATA

int32_t sml_recognition_run(signed short *data_batch, int32_t batch_sz, uint8_t num_sensors, uint32_t sensor_id)
{
	int32_t ret;

	int32_t batch_index = 0;
	signed short* data;
	for(batch_index=0; batch_index < batch_sz; batch_index++)
	{
	#ifdef SML_USE_TEST_DATA
        ret = kb_run_model((SENSOR_DATA_T*)&testdata[td_index++], TD_NUMCOLS, 0);
        if(td_index >= TD_NUMROWS)
        {
            td_index = 0;
        }
        if(ret >= 0)
        {
            sml_output_results(0, ret);
            kb_reset_model(0);
        }
	#else
        data = &data_batch[batch_index*num_sensors];
        ret = kb_run_model((SENSOR_DATA_T *)data, num_sensors, KB_MODEL_FAN_STATE_MONITORING_DEMO_RANK_0_INDEX);
		if (ret >= 0){
			sml_output_results(KB_MODEL_FAN_STATE_MONITORING_DEMO_RANK_0_INDEX, ret);
			kb_reset_model(0);
		};
	#endif //SML_USE_TEST_DATA
	}
	return ret;
}
