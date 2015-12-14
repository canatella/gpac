cmake_minimum_required(VERSION 3.1)
include (${VG_CONFIGURATION})

project (gpac)
find_package (PkgConfig)
find_package (android)
find_package (ffmpeg)

set (SRC
  src/compositor/mpeg4_animstream.c
  src/compositor/mpeg4_geometry_ifs2d.c
  src/compositor/mpeg4_textures.c
  src/compositor/mpeg4_bitmap.c
  src/compositor/mpeg4_grouping.c
  src/compositor/mpeg4_sound.c
  src/compositor/mpeg4_grouping_3d.c
  src/compositor/mpeg4_layer_3d.c
  src/compositor/mpeg4_path_layout.c
  src/compositor/mpeg4_geometry_2d.c
  src/compositor/mpeg4_geometry_3d.c
  src/compositor/mpeg4_geometry_ils2d.c
  src/compositor/mpeg4_sensors.c
  src/compositor/mpeg4_form.c
  src/compositor/mpeg4_audio.c
  src/compositor/mpeg4_background.c
  src/compositor/mpeg4_layout.c
  src/compositor/mpeg4_grouping_2d.c
  src/compositor/mpeg4_viewport.c
  src/compositor/mpeg4_layer_2d.c
  src/compositor/mpeg4_text.c
  src/compositor/mpeg4_timesensor.c
  src/compositor/mpeg4_composite.c
  src/compositor/mpeg4_background2d.c
  src/compositor/mpeg4_lighting.c
  src/compositor/mpeg4_gradients.c
  src/compositor/mesh.c
  src/compositor/mesh_collide.c
  src/compositor/mesh_tesselate.c
  src/compositor/navigate.c
  src/compositor/texturing_gl.c
  src/compositor/audio_mixer.c
  src/compositor/compositor.c
  src/compositor/camera.c
  src/compositor/drawable.c
  src/compositor/events.c
  src/compositor/offscreen_cache.c
  src/compositor/visual_manager.c
  src/compositor/audio_input.c
  src/compositor/compositor_node_init.c
  src/compositor/visual_manager_2d.c
  src/compositor/x3d_geometry.c
  src/compositor/texturing.c
  src/compositor/audio_render.c
  src/compositor/compositor_2d.c
  src/compositor/visual_manager_3d_gl.c
  src/compositor/font_engine.c
  src/compositor/bindable.c
  src/compositor/visual_manager_2d_draw.c
  src/compositor/visual_manager_3d.c
  src/compositor/compositor_3d.c
  src/compositor/hardcoded_protos.c
  src/compositor/hc_flash_shape.c
  src/compositor/svg_geometry.c
  src/media_tools/filestreamer.c
  src/media_tools/dash_segmenter.c
  src/media_tools/mpeg2_ps.c
  src/media_tools/img.c
  src/media_tools/mpegts.c
  src/media_tools/av_parsers.c
  src/media_tools/m2ts_mux.c
  src/media_tools/reedsolomon.c
  src/media_tools/dash_client.c
  src/media_tools/mpd.c
  src/media_tools/m3u8.c
  src/utils/alloc.c
  src/utils/os_net.c
  src/utils/path2d_stroker.c
  src/utils/zutil.c
  src/utils/os_divers.c
  src/utils/path2d.c
  src/utils/base_encoding.c
  src/utils/module.c
  src/utils/uni_bidi.c
  src/utils/dlmalloc.c
  src/utils/math.c
  src/utils/xml_parser.c
  src/utils/os_module.c
  src/utils/url.c
  src/utils/downloader.c
  src/utils/list.c
  src/utils/error.c
  src/utils/bitstream.c
  src/utils/color.c
  src/utils/token.c
  src/utils/configfile.c
  src/utils/utf.c
  src/utils/os_thread.c
  src/utils/os_file.c
  src/utils/cache.c
  src/utils/sha1.c
  src/utils/unicode.c
  src/terminal/scene.c
  src/terminal/terminal.c
  src/terminal/network_service.c
  src/terminal/input_sensor.c
  src/terminal/media_sensor.c
  src/terminal/media_object.c
  src/terminal/channel.c
  src/terminal/term_node_init.c
  src/terminal/object_browser.c
  src/terminal/mpeg4_inline.c
  src/terminal/decoder.c
  src/terminal/media_manager.c
  src/terminal/media_memory.c
  src/terminal/clock.c
  src/terminal/svg_external.c
  src/terminal/media_control.c
  src/terminal/object_manager.c
  src/scenegraph/xml_ns.c
  src/scenegraph/commands.c
  src/scenegraph/vrml_tools.c
  src/scenegraph/vrml_route.c
  src/scenegraph/dom_events.c
  src/scenegraph/smil_anim.c
  src/scenegraph/mpeg4_valuator.c
  src/scenegraph/svg_smjs.c
  src/scenegraph/vrml_interpolators.c
  src/scenegraph/svg_attributes.c
  src/scenegraph/mpeg4_nodes.c
  src/scenegraph/vrml_smjs.c
  src/scenegraph/mpeg4_animators.c
  src/scenegraph/dom_smjs.c
  src/scenegraph/svg_properties.c
  src/scenegraph/xbl_process.c
  src/scenegraph/svg_types.c
  src/scenegraph/x3d_nodes.c
  src/scenegraph/base_scenegraph.c
  src/scenegraph/smil_timing.c
  src/scenegraph/vrml_script.c
  src/scenegraph/vrml_proto.c
  src/scenegraph/html5_media_smjs.c
  src/scenegraph/html5_mse_smjs.c
  src/odf/ipmpx_dump.c
  src/odf/odf_code.c
  src/odf/desc_private.c
  src/odf/slc.c
  src/odf/odf_codec.c
  src/odf/qos.c
  src/odf/ipmpx_parse.c
  src/odf/ipmpx_code.c
  src/odf/odf_dump.c
  src/odf/odf_parse.c
  src/odf/odf_command.c
  src/odf/oci_codec.c
  src/odf/descriptors.c

  # local file support
  src/media_tools/isom_tools.c
  src/isomedia/avc_ext.c
  src/isomedia/track.c
  src/isomedia/isom_read.c
  src/isomedia/box_funcs.c
  src/isomedia/box_dump.c
  src/isomedia/box_code_drm.c
  src/isomedia/box_code_meta.c
  src/isomedia/box_code_base.c
  src/isomedia/box_code_adobe.c
  src/isomedia/box_code_apple.c
  src/isomedia/sample_descs.c
  src/isomedia/meta.c
  src/isomedia/stbl_read.c
  src/isomedia/box_code_3gpp.c
  src/isomedia/isom_intern.c
  src/isomedia/isom_write.c
  src/isomedia/drm_sample.c
  src/isomedia/ttml.c
  src/isomedia/tx3g.c
  src/isomedia/hint_track.c
  src/isomedia/stbl_write.c
  src/isomedia/data_map.c
  src/isomedia/media.c
  src/isomedia/hinting.c
  src/isomedia/isom_store.c
  src/isomedia/movie_fragments.c
  src/isomedia/media_odf.c
  src/isomedia/iff.c
  modules/isom_in/isom_cache.c
  modules/isom_in/load.c
  modules/isom_in/read.c
  modules/isom_in/read_ch.c

  # required modules
  modules/mpd_in/mpd_in.c
  modules/aac_in/aac_in.c
  modules/aac_in/faad_dec.c
  modules/ffmpeg_in/ffmpeg_load.c
  modules/ffmpeg_in/ffmpeg_demux.c
  modules/ffmpeg_in/ffmpeg_decode.c
  modules/mpegts_in/mpegts_in.c
  modules/soft_raster/ftgrays.c
  modules/soft_raster/raster_load.c
  modules/soft_raster/raster_565.c
  modules/soft_raster/raster_argb.c
  modules/soft_raster/raster_rgb.c
  modules/soft_raster/stencil.c
  modules/soft_raster/surface.c

  modules/mpd_in/mpd_in.c
  modules/odf_dec/odf_dec.c
  modules/rtp_in/rtp_in.c
  modules/rtp_in/rtp_session.c
  modules/rtp_in/rtp_signaling.c
  modules/rtp_in/rtp_stream.c
  modules/rtp_in/sdp_fetch.c
  modules/rtp_in/sdp_load.c
  modules/timedtext/timedtext_dec.c
  modules/timedtext/timedtext_in.c
  modules/osd/osd.c
  modules/bifs_dec/bifs_dec.c
  modules/ctx_load/ctx_load.c
  modules/dummy_in/dummy_in.c
  modules/raw_out/raw_video.c
  modules/saf_in/saf_in.c
  modules/audio_filter/audio_filter.c
  modules/img_in/img_in.c
  modules/img_in/bmp_dec.c
  modules/img_in/img_dec.c
  modules/img_in/jp2_dec.c
  modules/img_in/jpeg_dec.c
  modules/img_in/png_dec.c
  modules/ismacryp/isma_ea.c
  )

pkg_check_modules(FAAD2 REQUIRED faad2)

execute_process (
  COMMAND git rev-parse --short HEAD
  WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
  OUTPUT_VARIABLE GIT_REVISION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

if (ANDROID)
  list (APPEND SRC
    modules/droid_audio/droidaudio.c
    modules/droid_audio/javaenv.c
    modules/droid_mpegv/droid_mpegv.c
    modules/droid_out/droid_vout.c
    )

  pkg_check_modules(ANDROID_GLES REQUIRED android-gl)
  pkg_check_modules(ANDROID_LOG  REQUIRED android-log)
endif()

add_library (gpac STATIC ${SRC})
target_compile_options (gpac PRIVATE
  -Wall -Werror
  -Wno-type-limits -Wno-unused-parameter
  -Wno-unused-variable -Wno-format-extra-args
  -Wno-parentheses
  -Wno-return-type
  -Wno-unused-but-set-variable
  -Wno-implicit-function-declaration
  -Wno-pointer-sign
  -Wno-sign-compare
  -Wno-deprecated-declarations
  -Wno-error
  )
target_compile_definitions (gpac PUBLIC
  GPAC_GIT_REVISION=git-${GIT_REVISION}
  GPAC_DISABLE_SVG
  GPAC_DISABLE_SCENEGRAPH
  GPAC_DISABLE_SMGR
  GPAC_DISABLE_X3D
  GPAC_MINIMAL_ODF
  GPAC_DISABLE_BIFS
  GPAC_DISABLE_LASER
  GPAC_DISABLE_SAF
  GPAC_DISABLE_SENG
  GPAC_DISABLE_QTVR
  GPAC_DISABLE_AVILIB
  GPAC_DISABLE_OGG
  GPAC_DISABLE_MEDIA_EXPORT
  GPAC_DISABLE_SWF_IMPORT
  GPAC_DISABLE_SCENE_STATS
  GPAC_DISABLE_SCENE_DUMP
  GPAC_DISABLE_LOADER_BT
  GPAC_DISABLE_LOADER_XMT
  GPAC_DISABLE_MCRYPT
  GPAC_DISABLE_ISOM_WRITE
  GPAC_DISABLE_OD_DUMP
  GPAC_DISABLE_ISOM_DUMP
  GPAC_DISABLE_STREAMING
  GPAC_DISABLE_TTXT
  GPAC_DISABLE_TTML
  GPAC_DISABLE_VOBSUB
  GPAC_DISABLE_VTT
  GPAC_DISABLE_VALIDATOR
  GPAC_DISABLE_CLIPPING
  GPAC_DISABLE_LIGHTS
  $<$<CONFIG:release>:GPAC_DISABLE_LOG>
)
target_include_directories (gpac BEFORE PRIVATE
  include
  ${FAAD2_INCLUDE_DIRS}
  ${AVFORMAT_INCLUDE_DIRS}
  ${AVCODEC_INCLUDE_DIRS}
  ${AVUTIL_INCLUDE_DIRS}
  ${SWSCALE_INCLUDE_DIRS}
)
if (ANDROID)

  target_compile_definitions(gpac PUBLIC
    GPAC_ANDROID
    GPAC_CONFIG_ANDROID
    GPAC_HAS_FAAD
    GPAC_HAS_FFMPEG
    GPAC_STATIC_MODULES
    GPAC_USE_GLES2
    NO_MALLINFO
    XP_UNIX
    GPAC_MODULE_CUSTOM_LOAD
    )

  target_compile_options(gpac PRIVATE -fno-exceptions -fno-signed-char)
  target_include_directories (gpac PRIVATE
    generated/android
    )

  target_link_libraries (gpac
    PUBLIC log GLESv2 avformat avcodec avutil swscale
           ${FAAD2_LDFLAGS})

endif ()

install (TARGETS gpac DESTINATION lib EXPORT gpac-targets)
install (EXPORT gpac-targets DESTINATION ${CMAKE_MODULE_PREFIX})
install (FILES Findgpac.cmake DESTINATION ${CMAKE_MODULE_PREFIX})
install (DIRECTORY shaders/ DESTINATION ${JAVA_INSTALL_PREFIX}/vip-platform/assets)
install (DIRECTORY include/ DESTINATION include)
